#define FPC_TARGET_METAL
//#define FPC_LOGGING
#include "nbody_kernels.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printArray(float* array, int n, int start=0){
    printf("[");
    printf("[%f,%f,%f]\n",array[start*3],array[start*3+1],array[start*3+2]);
    for (int i = start+1; i < (start+n-1); i++){
        printf(" [%f,%f,%f]\n",array[i*3],array[i*3+1],array[i*3+2]);
    }
    printf(" [%f,%f,%f]",array[(start+n-1)*3],array[(start+n-1)*3+1],array[(start+n-1)*3+2]);
    printf("]\n");
}

int main(){
    
    FPC_init();

    srand(12032001);

    int n = 16384;
    float dt = 0.05;
    int nsteps = 50;

    int blockSize = 512;
    int numBlocks = 32;

    float* h_pos = (float*)malloc(n * 3 * sizeof(float));
    float* h_acc = (float*)malloc(n * 3 * sizeof(float));
    float* h_vel = (float*)malloc(n * 3 * sizeof(float));

    for (int i = 0; i < (n*3); i++){
        h_pos[i] = (((float)rand())/((float)RAND_MAX))*10;
        h_vel[i] = 0;
    }

    printArray(h_pos,5,16000);

    FPC::Buffer d_pos;
    FPC::Buffer d_acc;
    FPC::Buffer d_vel;

    d_pos.allocate<float>(n*3);
    d_acc.allocate<float>(n*3);
    d_vel.allocate<float>(n*3);

    d_pos.set(h_pos);
    d_vel.set(h_vel);

    long first,second;

    calc_acc({numBlocks},{blockSize},d_pos,d_acc,n);
    add2D({numBlocks},{blockSize},d_acc,0.5*dt,d_vel);
    first = clock();
    for (int i = 0; i < nsteps; i++){
        add2D({numBlocks},{blockSize},d_vel,1*dt,d_pos);
        calc_acc({numBlocks},{blockSize},d_pos,d_acc,n);
        add2D({numBlocks},{blockSize},d_acc,1*dt,d_vel);
    }

    second = clock();

    double time = ((double)(second-first))/((double)CLOCKS_PER_SEC);

    d_pos.get(h_pos);

    printArray(h_pos,5,16000);

    printf("\n\nTime (s): %f\n",time);
    printf("Per Step (s): %f\n",time / nsteps);

    free(h_pos);
    free(h_acc);
    free(h_vel);

    return 0;
}