cmake_minimum_required(VERSION 3.2)

project(DataStruct)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)

enable_testing()

set(CMAKE_DATASTRUCR_DIR_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdpart/googletest-1.14.0 googletest)

add_subdirectory(DynamicArray)
add_subdirectory(vector)

add_subdirectory(tests)

