cmake_minimum_required(VERSION 2.8)

project(lighthead C CXX ASM)

add_subdirectory(perf)

enable_testing()
add_subdirectory(test)
