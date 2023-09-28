
#define FPC_TARGET_METAL
#include "/Users/humzaqureshi/GitHub/FPC/include/fpc.hpp"
#include <stdlib.h>
#include <stdio.h>

void FPC_init(){
FPC::lib.load_library("/Users/humzaqureshi/GitHub/FPC/examples/nbody_fpclib/__fpctemp__2.metallib");
FPC::lib.load_kernel("add2D");
FPC::lib.load_kernel("calc_acc");
}
void add2D(const int (&num_blocks)[1], const int (&block_size)[1], FPC::Buffer in, float mul, FPC::Buffer out)
{
MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], 1, 1);
MTL::Size m_thread_group_size = MTL::Size(block_size[0], 1, 1);
FPC::lib.dispatch_function("add2D",m_grid_size,m_thread_group_size,in,mul,out,block_size[0],1,1);
}

void add2D(const int (&num_blocks)[2], const int (&block_size)[2], FPC::Buffer in, float mul, FPC::Buffer out)
{
MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], block_size[1] * num_blocks[1], 1);
MTL::Size m_thread_group_size = MTL::Size(block_size[0], block_size[1], 1);
FPC::lib.dispatch_function("add2D",m_grid_size,m_thread_group_size,in,mul,out,block_size[0],block_size[1],1);
}

void add2D(const int (&num_blocks)[3], const int (&block_size)[3], FPC::Buffer in, float mul, FPC::Buffer out)
{
MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], block_size[1] * num_blocks[1], block_size[2] * num_blocks[2]);
MTL::Size m_thread_group_size = MTL::Size(block_size[0], block_size[1], block_size[2]);
FPC::lib.dispatch_function("add2D",m_grid_size,m_thread_group_size,in,mul,out,block_size[0],block_size[1],block_size[2]);
}

void calc_acc(const int (&num_blocks)[1], const int (&block_size)[1], FPC::Buffer in, FPC::Buffer out, int n)
{
MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], 1, 1);
MTL::Size m_thread_group_size = MTL::Size(block_size[0], 1, 1);
FPC::lib.dispatch_function("calc_acc",m_grid_size,m_thread_group_size,in,out,n,block_size[0],1,1);
}

void calc_acc(const int (&num_blocks)[2], const int (&block_size)[2], FPC::Buffer in, FPC::Buffer out, int n)
{
MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], block_size[1] * num_blocks[1], 1);
MTL::Size m_thread_group_size = MTL::Size(block_size[0], block_size[1], 1);
FPC::lib.dispatch_function("calc_acc",m_grid_size,m_thread_group_size,in,out,n,block_size[0],block_size[1],1);
}

void calc_acc(const int (&num_blocks)[3], const int (&block_size)[3], FPC::Buffer in, FPC::Buffer out, int n)
{
MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], block_size[1] * num_blocks[1], block_size[2] * num_blocks[2]);
MTL::Size m_thread_group_size = MTL::Size(block_size[0], block_size[1], block_size[2]);
FPC::lib.dispatch_function("calc_acc",m_grid_size,m_thread_group_size,in,out,n,block_size[0],block_size[1],block_size[2]);
}


