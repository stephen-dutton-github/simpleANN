cmake_minimum_required(VERSION 3.24)
project(simpleANN C)

set(CMAKE_C_STANDARD 17)
include(CTest)

add_executable(simpleANN main.c nodeTests.c node.c node.h nodeTests.h nodeTests.c stack.c stack.h)



