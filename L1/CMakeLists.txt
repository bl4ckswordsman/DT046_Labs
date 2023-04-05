cmake_minimum_required(VERSION 3.24)
project(DT046_L1)

set(CMAKE_CXX_STANDARD 17)


add_executable(DT046_Labs main.cpp reader.h reader.cpp edges.txt dfs.h bfs.h)
