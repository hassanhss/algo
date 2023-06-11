cmake_minimum_required(VERSION 3.24)
project(algo C)

set(CMAKE_C_STANDARD 11)

add_executable(algo main.c)

add_subdirectory(struct-array)
add_subdirectory(pointer-array)
add_subdirectory(lists)
add_subdirectory(two-sum)
