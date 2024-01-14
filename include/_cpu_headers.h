#include "vector_types.h"

#define __host__

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