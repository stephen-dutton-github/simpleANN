cmake_minimum_required(VERSION 3.24)
project(simpleANN C)

set(CMAKE_C_STANDARD 17)
include(CTest)

add_executable(simpleANN main.c node.c)
add_executable(simpleANN_Tests nodeTests.c node.c node.h nodeTests.h nodeTests.c)
message(STATUS "Starting Tests")
add_test(NAME TestAll COMMAND simpleANN_Tests)


