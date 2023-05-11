
#define FPC_TARGET_METAL
#define FPC_LOGGING
#include "/Users/humzaqureshi/GitHub/FPC/src/wrappers/fpcc_wrapper.hpp"
#include <stdlib.h>
#include <stdio.h>

void FPC_init(){
FPC::lib.load_library("/Users/humzaqureshi/GitHub/FPC/__fpctemp__2.metallib");
FPC::lib.load_kernel("add_arrays");
}
void add_arrays(const int (&num_blocks)[1], const int (&block_size)[1], FPC::Buffer inA, FPC::Buffer inB, FPC::Buffer result, float a)
{
MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], 1, 1);
MTL::Size m_thread_group_size = MTL::Size(block_size[0], 1, 1);
FPC::lib.dispatch_function("add_arrays",m_grid_size,m_thread_group_size,inA,inB,result,a);
}

void add_arrays(const int (&num_blocks)[2], const int (&block_size)[2], FPC::Buffer inA, FPC::Buffer inB, FPC::Buffer result, float a)
{
MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], block_size[1] * num_blocks[1], 1);
MTL::Size m_thread_group_size = MTL::Size(block_size[0], block_size[1], 1);
FPC::lib.dispatch_function("add_arrays",m_grid_size,m_thread_group_size,inA,inB,result,a);
}

void add_arrays(const int (&num_blocks)[3], const int (&block_size)[3], FPC::Buffer inA, FPC::Buffer inB, FPC::Buffer result, float a)
{
MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], block_size[1] * num_blocks[1], block_size[2] * num_blocks[2]);
MTL::Size m_thread_group_size = MTL::Size(block_size[0], block_size[1], block_size[2]);
FPC::lib.dispatch_function("add_arrays",m_grid_size,m_thread_group_size,inA,inB,result,a);
}


