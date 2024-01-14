cmake_minimum_required(VERSION 3.2)

project(DynamicArray)

include_directories(${CMAKE_SOURCE_DIR})

add_library(DynamicArray SHARED DynamicArray.cpp)

add_executable(main main.cpp)
target_link_libraries(main DynamicArray)
