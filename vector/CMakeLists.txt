cmake_minimum_required(VERSION 3.2)

project(vector LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_library(vector_lib SHARED vector.h vector.cpp)
target_include_directories(vector_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

