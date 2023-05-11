#define FPC_TARGET_METAL
#define FPC_LOGGING
//#include "src/include/fpc.hpp"
//#include "test.fpc"
#include "test_lib.hpp"
#include <stdlib.h>
#include <stdio.h>

int main(){
    
    FPC_init();

    int array_size = 10;

    float* h_buff1 = (float*)malloc(array_size * sizeof(float));
    float* h_buff2 = (float*)malloc(array_size * sizeof(float));
    float* h_result = (float*)malloc(array_size * sizeof(float));

    for (int i = 0; i < array_size; i++){
        h_buff1[i] = (float)i;
        h_buff2[i] = (float)i;
    }

    FPC::Buffer d_buff1;
    FPC::Buffer d_buff2;
    FPC::Buffer d_result;

    d_buff1.allocate<float>(array_size);
    d_buff2.allocate<float>(array_size);
    d_result.allocate<float>(array_size);
    d_buff1.set(h_buff1);
    d_buff2.set(h_buff2);

    float a = 10;

    add_arrays({1},{12},d_buff1,d_buff2,d_result,a);

    d_result.get(h_result);

    //for (int i = 0; i < array_size; i++){
    //    printf("%f,",h_result[i]);
    //}
    //printf("\n");
    
    d_buff1.set(h_result);
    d_buff2.set(h_result);

    add_arrays({1},{10},d_buff1,d_buff2,d_result,5);

    d_result.get(h_result);

    //for (int i = 0; i < array_size; i++){
    //    printf("%f,",h_result[i]);
    //}
    //printf("\n");

    free(h_buff1);
    free(h_buff2);
    free(h_result);

    return 0;
}