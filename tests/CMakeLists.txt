cmake_minimum_required(VERSION 3.2)

project(Test)

list(APPEND test_list
dynamic_array
vector
)

find_package(GTest REQUIRED)

foreach( test_current ${test_list})
add_executable(test_${test_current} ${CMAKE_CURRENT_SOURCE_DIR}/test_${test_current}.cpp)
target_include_directories(test_${test_current} PUBLIC ${GTEST_INCLUDE_DIRS})
target_include_directories(test_${test_current} PUBLIC ${CMAKE_DATASTRUCR_DIR_ROOT})
target_link_libraries(test_${test_current} PUBLIC ${test_current}_lib ${GTEST_LIBRARIES})

add_test(NAME test_${test_current} COMMAND test_${test_current})
endforeach()



