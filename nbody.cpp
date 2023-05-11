#define FPC_TARGET_METAL
//#define FPC_LOGGING
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "include/fpc_headers.hpp"


kernel add_arrays[i](const float* inA, const float* inB, float* result){
    result[thread.i] = inA[thread.i] + inB[thread.i];
}


int main(){
    
    FPC_init();

    int n = 10;

    int blockSize = 512;
    int numBlocks = 32;

    float* h_buff1 = (float*)malloc(n * sizeof(float));
    float* h_buff2 = (float*)malloc(n * sizeof(float));
    float* h_result = (float*)malloc(n * sizeof(float));

    for (int i = 0; i < (n*3); i++){
        h_buff1[i] = i;
        h_buff2[i] = i;
    }

    FPC::Buffer d_buff1;
    FPC::Buffer d_buff2;
    FPC::Buffer d_result;

    d_buff1.allocate<float>(n);
    d_buff2.allocate<float>(n);
    d_result.allocate<float>(n);

    d_buff1.set(h_buff1);
    d_buff1.set(h_buff2);

    long first,second;

    add_arrays({numBlocks},{blockSize},d_buff1,d_buff2,d_result);

    d_result.get(h_result);

    free(h_buff1);
    free(h_buff2);
    free(h_result);

    return 0;
}