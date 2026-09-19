cmake_minimum_required(VERSION 3.14)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall" CACHE INTERNAL "")

project(rec1)

add_executable(
  employee
  main.cpp
  addEmployee.cpp
  addEmployee.hpp
 )
