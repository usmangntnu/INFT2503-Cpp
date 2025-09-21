cmake_minimum_required(VERSION 3.10)

project(oving4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Oppgave 1
add_executable(oving4 oppgave1.cpp)

# Oppgave 2
add_executable(oppgave2 oppgave2.cpp)

# ---- GTKMM ----
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

target_link_libraries(oppgave2 ${GTKMM_LIBRARIES})
