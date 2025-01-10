#ifndef _FPC_FPC_HPP_
#define _FPC_FPC_HPP_

#include <cstdlib>
#include <iostream>
#include <utility>

#if !defined(FPC_BACKEND_CUDA) && !defined(FPC_BACKEND_CPU) &&                 \
    !defined(FPC_BACKEND_SYCL)
#define FPC_BACKEND_CPU
#endif

#ifdef FPC_BACKEND_SYCL
#include "fpc_sycl.hpp"
#endif

#ifdef FPC_BACKEND_CUDA
#define FPC_KERNEL_DEF __forceinline__ __device__
#else
#define FPC_KERNEL_DEF inline
#endif

namespace fpc {

struct LaunchParams {
    const std::size_t num_threads;
    const std::size_t blocksize_hint;
    explicit LaunchParams(const std::size_t num_threads_,
                          const std::size_t blocksize_hint_ = 64)
        : num_threads(num_threads_), blocksize_hint(blocksize_hint_) {}
};

class Kernel {
  public:
#if defined(FPC_BACKEND_CPU) || defined(FPC_BACKEND_SYCL)
    struct KernelLaunchDimensions {
        std::size_t x, y, z;
    };
    const KernelLaunchDimensions threadIdx;
    const KernelLaunchDimensions blockDim;
    const KernelLaunchDimensions blockIdx;
    const int warpSize = 1;
    Kernel(const std::size_t global_thread_idx,
           const std::size_t total_n_threads)
        : threadIdx{global_thread_idx, 0, 0}, blockDim{total_n_threads, 1, 1},
          blockIdx{0, 0, 0} {}
#endif
};

#ifdef FPC_BACKEND_CPU
template <typename KernelType, typename... Args>
static inline void launch(LaunchParams launch_params, Args... args) {
#ifdef _OPENMP
#pragma omp parallel for
#endif
    for (size_t i = 0; i < launch_params.num_threads; i++) {
        KernelType kernel(i, launch_params.num_threads);
        kernel(std::forward<Args>(args)...);
    }
}
#endif

#ifdef FPC_BACKEND_SYCL
template <typename KernelType, typename... Args>
static inline void launch(LaunchParams launch_params, Args... args) {
    auto& queue = fpc::get_sycl_queue();
    queue.submit([&](sycl::handler& cgh) {
        cgh.parallel_for(sycl::range<1>(launch_params.num_threads),
                         [=](sycl::id<1> idx) {
                             size_t i = idx[0];
                             KernelType kernel(i, launch_params.num_threads);
                             kernel(args...);
                         });
    });
}
#endif

#ifdef FPC_BACKEND_CUDA
inline void gpuAssert(cudaError_t code, const char* file, int line,
                      bool abort = true) {
    if (code != cudaSuccess) {
        fprintf(stderr, "GPUassert: %s %s %d\n", cudaGetErrorString(code), file,
                line);
        if (abort)
            exit(code);
    }
}

template <typename KernelType, typename... Args>
__global__ void fpc_cuda_launcher(std::size_t fpc_total_threads, Args... args) {
    KernelType kernel;
    kernel(args...);
}

template <typename KernelType, typename... Args>
static inline void launch(LaunchParams launch_params, Args... args) {
    const int numBlocks =
        (launch_params.num_threads + (launch_params.blocksize_hint - 1)) /
        launch_params.blocksize_hint;
    fpc_cuda_launcher<KernelType, Args...>
        <<<numBlocks, launch_params.blocksize_hint>>>(launch_params.num_threads,
                                                      args...);
    gpuAssert(cudaPeekAtLastError(), __FILE__, __LINE__);
}
#endif
} // namespace fpc

#endif // _FPC_FPC_HPP_