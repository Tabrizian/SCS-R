cmake_minimum_required(VERSION 2.8)

project(SCS-R CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -g -std=gnu11 ")
add_subdirectory(src)
