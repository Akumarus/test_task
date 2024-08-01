cmake_minimum_required(VERSION 3.20)

project(program2)

add_executable(${PROJECT_NAME} 
                main.cpp
                server_socket.cpp
                server_socket.h
                )