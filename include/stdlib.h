#ifndef _STDLIB_H_
#define _STDLIB_H_

#ifdef _vscode_
#include "_cpu_headers.h"
#endif

#define RAND_MAX 0x7fffffff

#define NULL ((void*)0)

typedef long unsigned int size_t;

void* memcpy(void* dest, const void* src, size_t n);

void* malloc(long unsigned int);

void free(void*);

int rand(void);

static inline fpcError_t fpcMalloc(void** in, size_t sz){
    *in = malloc(sz);
    if (*in == NULL)return fpcError;
    return fpcSuccess;
}

static inline fpcError_t fpcFree(void* in){
    free(in);
    return fpcSuccess;
}

static inline fpcError_t fpcMemcpy(void* dst, const void* src, size_t count, fpcMemcpyKind kind){
    memcpy(dst,src,count);
    return fpcSuccess;
}

#endif