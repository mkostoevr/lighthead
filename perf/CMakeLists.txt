set(CMAKE_CXX_STANDARD 17)

find_package(benchmark QUIET)
if (NOT ${benchmark_FOUND})
    message(AUTHOR_WARNING "Google Benchmark library was not found")
    return()
endif()

add_executable(vebtree vebtree.cc)
target_link_libraries(vebtree PUBLIC benchmark::benchmark)
