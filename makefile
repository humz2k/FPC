
.PHONY: all
all: example_cpu.o example_gpu.o example_sycl.o

FPC_CXX ?= c++

example_cpu.o: example.fpc include/fpc/fpc.hpp include/fpc/fpc_runtime.hpp
	bin/fpc -O3 --backend=cpu example.fpc -o example_cpu.o --cxx $(FPC_CXX) --verbose

example_gpu.o: example.fpc include/fpc/fpc.hpp include/fpc/fpc_runtime.hpp
	bin/fpc -O3 --backend=cuda example.fpc -o example_gpu.o -gencode=arch=compute_60,code=sm_60 --verbose

example_sycl.o: example.fpc include/fpc/fpc.hpp include/fpc/fpc_runtime.hpp
	bin/fpc -O3 --backend=sycl example.fpc -o example_sycl.o --cxx $(FPC_CXX) --verbose

clean:
	rm *.o