cmake_minimum_required(VERSION 3.2)

project(Test)

add_subdirectory(${CMAKE_DATASTRUCR_DIR_ROOT}/thirdpart/googletest-1.14.0 googletest)

add_executable(test_dynamic_array ${CMAKE_CURRENT_SOURCE_DIR}/test_dynamic_array.cpp)
target_include_directories(test_dynamic_array PUBLIC ${CMAKE_DATASTRUCR_DIR_ROOT}/thirdpart/googletest-1.14.0/googletest/include)
target_include_directories(test_dynamic_array PUBLIC ${CMAKE_DATASTRUCR_DIR_ROOT})
target_link_libraries(test_dynamic_array PUBLIC dynamic_array_lib gtest gtest_main)

add_test(NAME test_dynamic_array
         COMMAND test_dynamic_array)
