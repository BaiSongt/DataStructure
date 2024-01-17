cmake_minimum_required(VERSION 3.2)

project(Test)

list(APPEND test_list
test_dynamic_array
test_vector
)


add_subdirectory(${CMAKE_DATASTRUCR_DIR_ROOT}/thirdpart/googletest-1.14.0 googletest)
foreach( test_current ${test_list})
add_executable(${test_current} ${CMAKE_CURRENT_SOURCE_DIR}/${test_current}.cpp)
target_include_directories(${test_current} PUBLIC ${CMAKE_DATASTRUCR_DIR_ROOT}/thirdpart/googletest-1.14.0/googletest/include)
target_include_directories(${test_current} PUBLIC ${CMAKE_DATASTRUCR_DIR_ROOT})
target_link_libraries(${test_current} PUBLIC dynamic_array_lib gtest gtest_main)

add_test(NAME ${test_current} COMMAND ${test_current})
endforeach()



