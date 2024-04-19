cmake_minimum_required(VERSION 3.14)
project(linked_list)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    linked_list
    STATIC
    hj_list.h
    hj_list.c
)

add_executable(linked_list_example example.c)
target_link_libraries(linked_list_example PRIVATE linked_list)