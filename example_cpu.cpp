#include <fpc/fpc.hpp>
#include <iostream>

struct MyKernel : public fpc::Kernel {
using fpc::Kernel::Kernel;
void operator()(int* array){
    int idx = threadIdx.x + blockDim.x * blockIdx.x;
    printf("Hello from thread %d\n",idx);
    array[idx] = idx;
}
};

int main(){
    int array[256];
    fpc::launch<MyKernel>(fpc::LaunchParams(256,256),array);
    return 0;
}