example_cpu.o: example_cpu.cpp
	g++-14 example_cpu.cpp -Iinclude -DFPC_BACKEND_CPU -o example_cpu.o -fopenmp