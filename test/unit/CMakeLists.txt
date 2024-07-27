add_executable(vebtree.test vebtree.cc)
target_include_directories(vebtree.test PRIVATE ${CMAKE_SOURCE_DIR})
add_test(vebtree vebtree.test)

add_executable(bpstree.test bpstree.cc)
target_include_directories(bpstree.test PRIVATE ${CMAKE_SOURCE_DIR})
add_test(bpstree bpstree.test)
