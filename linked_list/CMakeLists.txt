cmake_minimum_required(VERSION 3.14)
project(linked_list)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    linked_list
    SHARED
    hj_list.h
    hj_list.c
)