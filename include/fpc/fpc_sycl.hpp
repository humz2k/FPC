#ifndef _FPC_FPC_SYCL_HPP_
#define _FPC_FPC_SYCL_HPP_
#include <CL/sycl.hpp>
namespace sycl = cl::sycl;

namespace fpc {
inline sycl::queue& get_sycl_queue() {
    static sycl::queue q{sycl::default_selector{}};
    return q;
}
} // namespace fpc
#endif