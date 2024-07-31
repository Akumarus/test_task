cmake_minimum_required(VERSION 3.20)

project(program1)

add_executable(${PROJECT_NAME} 
                main.cpp
                data_process.cpp
                data_process.h
                input_thread.cpp
                input_thread.h
                output_thread.cpp
                output_thread.h
                buffer.cpp
                buffer.h)