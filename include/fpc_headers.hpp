//#define FPC_TARGET_METAL
//#define FPC_LOGGING

#include <iostream>
#include <map>

void FPC_init();

namespace FPC{

    class Buffer{
        public:
            #ifdef FPC_TARGET_METAL
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
            #endif

    };

    class Lib{
        public:
            #ifdef FPC_TARGET_METAL
            std::map<const char*,MTL::ComputePipelineState*> m_pipe_states;
            std::map<const char*,MTL::Function*> m_functions;
            MTL::CommandQueue* m_command_queue;
            NS::AutoreleasePool* p_pool;
            MTL::Library* m_lib;
            NS::Error* error;
            MTL::Device* m_device;
            int buffers_bound;

            Lib(){
                #ifdef FPC_LOGGING
                std::cout << "Initializing" << std::endl;
                #endif
                p_pool = NS::AutoreleasePool::alloc()->init();
                m_device = MTL::CreateSystemDefaultDevice();
                m_command_queue = m_device->newCommandQueue();
                #ifdef FPC_LOGGING
                std::cout << "Initialized" << std::endl;
                #endif
            }

            void load_library(const char* lib_path);
            void load_kernel(const char* func_str);

            template<class T>
            int bind_buffer(T buff, MTL::ComputeCommandEncoder* m_compute_encoder);

            template<typename ...Args>
            int dispatch_function(const char* func_str, MTL::Size grid_size, MTL::Size thread_group_size, Args... args);

            void synchronize();

            ~Lib(){
                #ifdef FPC_LOGGING
                std::cout << "Finalizing" << std::endl;
                #endif
                p_pool->release();
                #ifdef FPC_LOGGING
                std::cout << "Finalized" << std::endl;
                #endif
            }
            #endif
    };

    FPC::Lib lib;

}
