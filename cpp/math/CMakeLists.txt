cmake_minimum_required(VERSION 3.28)
project(cgmath)

set(CMAKE_CXX_STANDARD 20)

add_library(cgmath
        Vector.cpp
        Vector.h)

target_include_directories(cgmath PUBLIC ${CMAKE_SOURCE_DIR})

find_package(GTest)

enable_testing()

add_executable(
        test_vector
        test_vector.cpp
)
target_link_libraries(
        test_vector
        GTest::gtest_main
)
target_include_directories(test_vector PRIVATE ${CMAKE_SOURCE_DIR})

include(GoogleTest)
gtest_discover_tests(test_vector)
