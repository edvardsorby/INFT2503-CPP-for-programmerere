cmake_minimum_required(VERSION 3.5)

project(oeving4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

INCLUDE(FindPkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(oppgave1 oppgave1.cpp)
add_executable(oppgave2 oppgave2.cpp)
target_link_libraries(oppgave2 ${GTKMM_LIBRARIES})
