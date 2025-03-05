cmake_minimum_required(VERSION 3.10)

project(MachineLearning)

set(EIGEN_INCLUDE_DIR /usr/include/eigen3)

include_directories(${EIGEN_INCLUDE_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dataset/iris.csv ${CMAKE_CURRENT_BINARY_DIR}/iris.csv COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dataset/california_housing.csv ${CMAKE_CURRENT_BINARY_DIR}/california_housing.csv COPYONLY)

add_executable(main 
  src/main.cpp
  src/lib/regression/regression.cpp
  src/lib/optimizer/optimizer.cpp
  src/lib/dataset/dataset.cpp
  src/lib/metrics/metrics.cpp
)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_VERBOSE_MAKEFILE ON)