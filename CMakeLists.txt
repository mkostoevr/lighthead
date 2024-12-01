cmake_minimum_required(VERSION 2.8)

project(lighthead C CXX ASM)

set(BENCHMARK_ENABLE_TESTING FALSE)
add_subdirectory(third_party/benchmark)

add_subdirectory(perf)

enable_testing()
add_subdirectory(test)
