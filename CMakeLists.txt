cmake_minimum_required(VERSION 3.24)
project(simpleANN C)

set(CMAKE_C_STANDARD 17)
include(CTest)

add_executable(simpleANN main.c node.h nodeTests.h stack.h node.c nodeTests.c stack.c)


