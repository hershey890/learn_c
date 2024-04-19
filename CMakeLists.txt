cmake_minimum_required(VERSION 3.14)
project(learn_c)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

####################################
#           Subdirectories         #
####################################
add_subdirectory(linked_list)
add_subdirectory(shared_memory)

####################################
#           GoogleTest             #
####################################
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/5197b1a8e6a1ef9f214f4aa537b0be17cbf91946.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    linked_list_test
    tests/linked_list_test.cpp
)
target_link_libraries(
    linked_list_test
    GTest::gtest_main
    linked_list
)

include(GoogleTest)
gtest_discover_tests(linked_list_test)