//#define FPC_TARGET_METAL
//#define FPC_LOGGING

#ifdef FPC_TARGET_METAL
#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#include <iostream>
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#endif
#include <map>

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

        template<typename T>
        void FPC::Buffer::allocate(int n_elements){
            #ifdef FPC_LOGGING
            std::cout << "Allocating Buffer" << std::endl;
            #endif
            size = n_elements;
            m_buff = FPC::lib.m_device->newBuffer(n_elements * sizeof(T),MTL::ResourceStorageModeShared);
        }

        template<typename T>
        void FPC::Buffer::set(const T* data){
            T* tmp = (T*)m_buff->contents();
            for (int i = 0; i < size; i++){
                tmp[i] = data[i];
            }
        }

        template<typename T>
        void FPC::Buffer::get(T* out_buff){
            T* tmp = (T*)m_buff->contents();
            for (int i = 0; i < size; i++){
                out_buff[i] = tmp[i];
            }
        }

        #ifdef FPC_TARGET_METAL
        void Lib::load_library(const char* lib_path){
            #ifdef FPC_LOGGING
            std::cout << "Loading library: " << lib_path << std::endl;
            #endif
            auto filePath = NS::String::string(lib_path,NS::UTF8StringEncoding);
            m_lib = m_device->newLibrary(filePath,&error);
            if (!m_lib){
                std::cerr << "Failed to load library: " << lib_path;
                std::exit(-1);
            }
            #ifdef FPC_LOGGING
            std::cout << "Loaded library: " << lib_path << std::endl;
            #endif
        }

        void Lib::load_kernel(const char* func_str){
            #ifdef FPC_LOGGING
            std::cout << "Loading kernel: " << func_str << std::endl;
            #endif
            auto func_name = NS::String::string(func_str,NS::ASCIIStringEncoding);
            m_functions[func_str] = m_lib->newFunction(func_name);
            if (!m_functions[func_str]){
                std::cerr << "Failed to find kernel: " << func_str;
            }
            m_pipe_states[func_str] = m_device->newComputePipelineState(m_functions[func_str], &error);
            #ifdef FPC_LOGGING
            std::cout << "Loaded kernel: " << func_str << std::endl;
            #endif

        }

        template<>
        int Lib::bind_buffer(FPC::Buffer buff, MTL::ComputeCommandEncoder* m_compute_encoder){
            #ifdef FPC_LOGGING
            std::cout << "Binding Buffer " << std::endl;
            #endif
            m_compute_encoder->setBuffer(buff.m_buff,0,buffers_bound);
            buffers_bound++;
            return 0;
        }

        template<class T>
        int Lib::bind_buffer(T buff, MTL::ComputeCommandEncoder* m_compute_encoder){
            #ifdef FPC_LOGGING
            std::cout << "Binding Buffer " << std::endl;
            #endif
            FPC::Buffer tmp;
            tmp.allocate<T>(1);
            tmp.set(&buff);
            m_compute_encoder->setBuffer(tmp.m_buff,0,buffers_bound);
            buffers_bound++;
            return 0;
        }

        template<typename ...Args>
        int Lib::dispatch_function(const char* func_str, MTL::Size grid_size, MTL::Size thread_group_size, Args... args){
            MTL::CommandBuffer* m_command_buffer;
            MTL::ComputeCommandEncoder* m_compute_encoder;
            m_command_buffer = m_command_queue->commandBuffer();
            m_compute_encoder = m_command_buffer->computeCommandEncoder();
            m_compute_encoder->setComputePipelineState(m_pipe_states[func_str]);
            buffers_bound = 0;
            int a[] = {0,bind_buffer(args,m_compute_encoder)...};
            m_compute_encoder->dispatchThreads(grid_size,thread_group_size);
            m_compute_encoder->endEncoding();
            m_command_buffer->commit();
            m_command_buffer->waitUntilCompleted();
            return a[0];
        }

        void Lib::synchronize(){
            
        }

        #endif

}
