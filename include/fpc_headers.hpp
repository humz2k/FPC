//#define FPC_TARGET_METAL
//#define FPC_LOGGING
#ifndef FPC_PREPROCESS
#include <iostream>
#include <map>

void FPC_init();

namespace FPC{

    class Buffer{
        public:
            MTL::Buffer* m_buff;
            int size;

            Buffer(){
                size = 0;
            }

            template<typename T>
            void allocate(int n_elements);

            template<typename T>
            void set(const T* data);

            template<typename T>
            void get(T* out_buff);

            ~Buffer(){

            }

    };

    class Lib{
        public:

            Lib(){
            }

            //void load_library(const char* lib_path);
            //void load_kernel(const char* func_str);

            //template<class T>
            //int bind_buffer(T buff, MTL::ComputeCommandEncoder* m_compute_encoder);

            //template<typename ...Args>
            //int dispatch_function(const char* func_str, MTL::Size grid_size, MTL::Size thread_group_size, Args... args);

            void synchronize();

            ~Lib(){
            }
    };

    FPC::Lib lib;

}

#endif
