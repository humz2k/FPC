#ifndef _FPC_FPC_HPP_
#define _FPC_FPC_HPP_

#include <cstdlib>
#include <utility>

#ifndef FPC_BACKEND_CPU
#define FPC_BACKEND_CPU
#endif

namespace fpc {

struct LaunchParams {
    const std::size_t num_threads;
    const std::size_t blocksize_hint;
    LaunchParams(const std::size_t num_threads_, const std::size_t blocksize_hint_) : num_threads(num_threads_), blocksize_hint(blocksize_hint_){}
};

class Kernel {
public:
    #ifdef FPC_BACKEND_CPU
    struct KernelLaunchDimensions {
        std::size_t x,y,z;
    };
    const KernelLaunchDimensions threadIdx;
    const KernelLaunchDimensions blockDim;
    const KernelLaunchDimensions blockIdx;
    const int warpSize = 1;
    Kernel(const std::size_t global_thread_idx, const std::size_t total_n_threads) : threadIdx{global_thread_idx,0,0}, blockDim{total_n_threads,1,1}, blockIdx{0,0,0}{}
    #endif
};

#ifdef FPC_BACKEND_CPU
template<typename KernelType, typename... Args>
static inline void launch(LaunchParams launch_params, Args... args){
#ifdef _OPENMP
#pragma omp parallel for
#endif
    for (size_t i = 0; i < launch_params.num_threads; i++){
        KernelType kernel(i,launch_params.num_threads);
        kernel(std::forward<Args>(args)...);
    }
}
#endif

} // namespace fpc

#endif // _FPC_FPC_HPP_