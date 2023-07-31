cmake_minimum_required(VERSION 3.24)
project(statemachine)

set(CMAKE_CXX_STANDARD 17)

add_library(statemachine STATIC statemachine.c)

add_executable(test main.c)
target_link_libraries(test PRIVATE statemachine)
