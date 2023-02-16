cmake_minimum_required(VERSION 3.24)
project(simpleANN C)

set(CMAKE_C_STANDARD 17)


enable_testing()
include(CTest)

add_executable(simpleANN main.c node.c nodeTests.h)
