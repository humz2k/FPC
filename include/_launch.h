#define _warpSize 32

#define _LAUNCH_KERNEL_MACRO(func,numBlocks,blockSize,shmem,stream,...) \
{\
    for (int _bidx = 0; _bidx < numBlocks; _bidx++){\
        _Pragma("omp parallel for")\
        for (int _warpidx = 0; _warpidx < blockSize; _warpidx++){\
            func(make_uint3(numBlocks,1,1),make_uint3(_bidx,0,0),make_uint3(blockSize,1,1),make_uint3(_warpidx,0,0),_warpSize, __VA_ARGS__);\
        }\
    }\
}

#define __global__
#define __device__
