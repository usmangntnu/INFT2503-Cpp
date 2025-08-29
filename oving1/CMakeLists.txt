cmake_minimum_required(VERSION 3.10)

project(oving1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(temperatures_a temperatures_a.cpp)
add_executable(temperatures_b temperatures_b.cpp)
