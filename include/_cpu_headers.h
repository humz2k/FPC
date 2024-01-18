#include "vector_types.h"

#define __host__
#define __forceinline__ inline
#define __restrict restrict
#define __restrict__ restrict

typedef enum {
    fpcSuccess = 0,
    fpcError = 1
} fpcError_t;

typedef enum {
    fpcMemcpyHostToHost = 0,
    fpcMemcpyHostToDevice = 1,
    fpcMemcpyDeviceToHost = 2,
    fpcMemcpyDeviceToDevice = 3,
    fpcMemcpyDefault = 4
} fpcMemcpyKind;