add_executable(vebtree.test vebtree.cc)
target_include_directories(vebtree.test PRIVATE ${CMAKE_SOURCE_DIR})

add_test(vebtree vebtree.test)
