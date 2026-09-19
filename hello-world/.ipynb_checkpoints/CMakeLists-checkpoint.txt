cmake_minimum_required(VERSION 3.14)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall" CACHE INTERNAL "")

project(hello_world)

add_executable(
  hello
  hello.cpp
 )
