cmake_minimum_required(VERSION 3.10)

project(Optimizer)

add_executable(main main.cpp optimizer.cpp)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_VERBOSE_MAKEFILE ON)