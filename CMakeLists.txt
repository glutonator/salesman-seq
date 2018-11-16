cmake_minimum_required(VERSION 3.12)
project(salesman_seq)

set(CMAKE_CXX_STANDARD 14)

add_executable(salesman_seq main.cpp Graph.cpp Graph.h RandomVector.cpp RandomVector.h Algorithm.cpp Algorithm.h)