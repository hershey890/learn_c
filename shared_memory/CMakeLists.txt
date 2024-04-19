cmake_minimum_required(VERSION 3.14)
project(pshm_buf)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
	pshm_buf
	STATIC
	pshm_buf.h
	pshm_buf.c	
)

add_executable(pshm_receive pshm_receive.c)
target_link_libraries(pshm_receive PRIVATE pshm_buf)

add_executable(pshm_send pshm_send.c)
target_link_libraries(pshm_send PRIVATE pshm_buf)
