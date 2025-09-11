cmake_minimum_required(VERSION 3.10)

project(oving3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(oving3
    main.cpp
    commodity.cpp
)

add_executable(oppgave4
    oppgave4.cpp
)
