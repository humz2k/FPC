#define FPC_TARGET_METAL
#define FPC_LOGGING
#include "fpcc_wrapper.hpp"
//#include <stdlib.h>
//#include <stdio.h>

void FPC_init(){
    FPC::lib.load_library("/Users/humzaqureshi/GitHub/FPC/__fpctemp__2.metallib");
    FPC::lib.load_kernel("add_arrays");
}

/*void add_arrays(const int (&num_blocks)[3], const int (&block_size)[3], FPC::Buffer inA, FPC::Buffer inB, FPC::Buffer result, int a){
    MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], block_size[1] * num_blocks[1], block_size[2] * num_blocks[2]);
    MTL::Size m_thread_group_size = MTL::Size(block_size[0], block_size[1], block_size[2]);
    FPC::lib.dispatch_function("add_arrays",m_grid_size,m_thread_group_size,inA,inB,result,a);
}

void add_arrays(const int (&num_blocks)[2], const int (&block_size)[2], FPC::Buffer inA, FPC::Buffer inB, FPC::Buffer result, int a){
    MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], block_size[1] * num_blocks[1], 1);
    MTL::Size m_thread_group_size = MTL::Size(block_size[0], block_size[1], 1);
    FPC::lib.dispatch_function("add_arrays",m_grid_size,m_thread_group_size,inA,inB,result,a);
}*/

void add_arrays(const int (&num_blocks)[1], const int (&block_size)[1], FPC::Buffer inA, FPC::Buffer inB, FPC::Buffer result, float a){
    MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], 1, 1);
    MTL::Size m_thread_group_size = MTL::Size(block_size[0], 1, 1);
    FPC::lib.dispatch_function("add_arrays",m_grid_size,m_thread_group_size,inA,inB,result,a);
}

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