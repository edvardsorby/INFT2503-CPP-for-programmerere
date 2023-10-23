cmake_minimum_required(VERSION 3.5)

project(oeving3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(circle_client circle_client.cpp)
add_executable(commodity_client commodity_client.cpp commodity.cpp)
add_executable(string string.cpp)
