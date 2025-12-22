cmake_minimum_required(VERSION 3.0.0)
project(marching_squares VERSION 1.0.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_executable(marching_squares 
    src/config.h 
    src/main.cpp 
    src/glad.c
)

target_include_directories(marching_squares PRIVATE dependencies)

target_link_libraries(marching_squares glfw OpenGL::GL)
