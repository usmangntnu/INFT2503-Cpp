cmake_minimum_required(VERSION 3.10)
project(ChessGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(chess
    main.cpp
)

add_executable(oppgave2 oppgave2.cpp)


# Link Boost (asio needs pthread on Linux)
find_package(Threads REQUIRED)
target_link_libraries(oppgave2 PRIVATE Threads::Threads)
