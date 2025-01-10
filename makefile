
.PHONY: all
all: example_cpu.o example_gpu.o

FPC_CXX ?= c++

example_cpu.o: example.fpc include/fpc/fpc.hpp include/fpc/fpc_runtime.hpp
	bin/fpc --backend=cpu example.fpc -o example_cpu.o --cxx $(FPC_CXX) --verbose

example_gpu.o: example.fpc include/fpc/fpc.hpp include/fpc/fpc_runtime.hpp
	bin/fpc --backend=cuda example.fpc -o example_gpu.o -gencode=arch=compute_60,code=sm_60 --verbose

clean:
	rm *.o