#include <fpc/fpc.hpp>
#include <fpc/fpc_runtime.hpp>
#include <iostream>

struct MyKernel : public fpc::Kernel {
using fpc::Kernel::Kernel;
FPC_KERNEL_DEF void operator()(int* array){
    int idx = threadIdx.x + blockDim.x * blockIdx.x;
    printf("Hello from thread %d\n",idx);
    array[idx] = idx;
}
};

int main(){
    int* array;
    fpcMalloc(&array,256 * sizeof(int));
    fpc::launch<MyKernel>(fpc::LaunchParams(256,256),array);
    int h_array[256];
    fpcMemcpy(h_array,array,256 * sizeof(int),fpcMemcpyDeviceToHost);
    for (int i = 0; i < 256; i++){
        std::cout << h_array[i] << std::endl;
    }
    fpcFree(array);
    return 0;
}