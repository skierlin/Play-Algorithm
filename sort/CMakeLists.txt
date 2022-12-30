cmake_minimum_required(VERSION 3.20)
project(sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(select_sort select_sort.cpp)
add_executable(insert_sort insert_sort.cpp)
add_executable(merge_sort merge_sort.cpp)
add_executable(quick_sort quick_sort.cpp)
