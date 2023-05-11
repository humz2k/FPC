CC=clang++
CFLAGS=-Wall -std=c++17 -I./metal-cpp -I./metal-cpp-extensions -fno-objc-arc $(DBG_OPT_FLAGS) $(ASAN_FLAGS)
LDFLAGS=-framework Metal -framework Foundation -framework Cocoa -framework CoreGraphics -framework MetalKit 

VPATH=./metal-cpp

main:
	$(CC) test.cpp $(CFLAGS) $(LDFLAGS) -o test.o	

wrapper:
	$(CC) src/wrappers/fpcc_wrapper.cpp $(CFLAGS) $(LDFLAGS) -o wrapper.o	

