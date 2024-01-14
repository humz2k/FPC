
#define type char
#define typename char
#include "_vector_types.h"

#define type unsigned char
#define typename uchar
#include "_vector_types.h"

#define type short
#define typename short
#include "_vector_types.h"

#define type unsigned short
#define typename ushort
#include "_vector_types.h"

#define type int
#define typename int
#include "_vector_types.h"

#define type unsigned int
#define typename uint
#include "_vector_types.h"

#define type long
#define typename long
#include "_vector_types.h"

#define type unsigned long
#define typename ulong
#include "_vector_types.h"

#define type long long
#define typename longlong
#include "_vector_types.h"

#define type unsigned long long
#define typename ulonglong
#include "_vector_types.h"

#define type float
#define typename float
#include "_vector_types.h"

#define type double
#define typename double
#include "_vector_types.h"

typedef uint3 dim3;

static inline dim3 _make_dim_3(int in[], int n){
    if (n == 1){
        return make_uint3(in[0],1,1);
    }
    if (n == 2){
        return make_uint3(in[0],in[1],1);
    }
    if (n == 3){
        return make_uint3(in[0],in[1],in[2]);
    }
    return make_uint3(1,1,1);
}

#define make_dim3(...) _make_dim_3((int[]){__VA_ARGS__},(sizeof((int[]){__VA_ARGS__})/sizeof(int)))