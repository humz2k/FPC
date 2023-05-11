CC=clang++
CFLAGS=-Wall -std=c++17 -I./metal-cpp -I./metal-cpp-extensions -fno-objc-arc $(DBG_OPT_FLAGS) $(ASAN_FLAGS)
LDFLAGS=-framework Metal -framework Foundation -framework Cocoa -framework CoreGraphics -framework MetalKit 

VPATH=./metal-cpp

main:
	fpclib test.fpc --target Metal -o test_lib.hpp --save-temps
	$(CC) test.cpp $(CFLAGS) $(LDFLAGS) -o test.o	

clean:
	rm *.o
	rm test_lib.hpp
	rm *.metallib
