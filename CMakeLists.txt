cmake_minimum_required(VERSION 3.27)
project(LSA_GA3AN)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(snippets)

add_executable(LSA_GA3AN
        reference.cpp)
