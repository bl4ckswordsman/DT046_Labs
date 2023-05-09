cmake_minimum_required(VERSION 3.24)
project(DT046G_L3)

set(CMAKE_CXX_STANDARD 17)

add_executable(DT046G_L3 main.cpp data_gen.h data_gen.cpp search_alg.h search_alg.cpp data_reporting.cpp data_reporting.h)
