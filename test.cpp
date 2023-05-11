#define FPC_TARGET_METAL
#define FPC_LOGGING
//#include "src/include/fpc.hpp"
//#include "test.fpc"
#include "test_lib.hpp"
#include <stdlib.h>
#include <stdio.h>

int main(){
    
    FPC_init();

    int n = 10;

    float* h_buff1 = (float*)malloc(n * 3 * sizeof(float));
    float* h_buff2 = (float*)malloc(n * sizeof(float));

    for (int i = 0; i < n*3; i++){
        h_buff1[i] = ((float)rand())/((float)RAND_MAX);
    }

    FPC::Buffer d_buff1;
    FPC::Buffer d_buff2;
    FPC::Buffer d_result;

    d_buff1.allocate<float>(n*3);
    d_buff2.allocate<float>(n);

    d_buff1.set(h_buff1);
    //d_buff2.set(h_buff2);

    rsqracc({1},{10},d_buff1,d_buff2,n);

    

    free(h_buff1);
    free(h_buff2);

    return 0;
}