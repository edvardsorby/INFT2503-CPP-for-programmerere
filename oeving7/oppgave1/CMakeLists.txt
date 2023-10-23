cmake_minimum_required(VERSION 3.5)

project(oeving7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(oppgave1 main.cpp fraction.cpp)
