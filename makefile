example_cpu.o: example_cpu.cpp
	c++ example_cpu.cpp -Iinclude -DFPC_BACKEND_CPU -o example_cpu.o -fopenmp

example_gpu.o: example_gpu.cu
	nvcc example_gpu.cu -Iinclude -DFPC_BACKEND_CUDA -lineinfo -Xptxas -v -Xcompiler="-fPIC" -gencode=arch=compute_60,code=sm_60 -o example_gpu.o