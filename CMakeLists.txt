cmake_minimum_required(VERSION 3.2)

project(DataStruct)

enable_testing()

set(CMAKE_DATASTRUCR_DIR_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdpart/googletest-1.14.0 googletest)

add_subdirectory(DynamicArray)
add_subdirectory(tests)

