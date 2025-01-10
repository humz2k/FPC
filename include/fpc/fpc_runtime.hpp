#ifndef _FPC_FPC_RUNTIME_HPP_
#define _FPC_FPC_RUNTIME_HPP_

#include <cstdlib>
#include <cstring>

#if !defined(FPC_BACKEND_CUDA) && !defined(FPC_BACKEND_CPU)
#define FPC_BACKEND_CPU
#endif

#ifdef FPC_BACKEND_CUDA
#include <cuda_runtime.h>
#endif

using fpcError_t = int;

enum fpcMemcpyKind {
    fpcMemcpyHostToHost = 0,
    fpcMemcpyHostToDevice = 1,
    fpcMemcpyDeviceToHost = 2,
    fpcMemcpyDeviceToDevice = 3,
    fpcMemcpyDefault = 4
};

template<typename T>
inline fpcError_t fpcMalloc(T** devptr, std::size_t size){
    #ifdef FPC_BACKEND_CUDA
    return cudaMalloc(devptr,size);
    #endif
    #ifdef FPC_BACKEND_CPU
    *devptr = (T*)malloc(size);
    return 0;
    #endif
}

inline fpcError_t fpcFree(void* ptr){
    #ifdef FPC_BACKEND_CUDA
    return cudaFree(ptr);
    #endif
    #ifdef FPC_BACKEND_CPU
    free(ptr);
    return 0;
    #endif
}

inline fpcError_t fpcMemcpy(void* dst, const void* src, std::size_t size, fpcMemcpyKind kind){
    #ifdef FPC_BACKEND_CUDA
    return cudaMemcpy(dst,src,size,(cudaMemcpyKind)kind);
    #endif
    memcpy(dst,src,size);
    return 0;
}

#endif // _FPC_FPC_RUNTIME_HPP_