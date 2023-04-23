cmake_minimum_required(VERSION 3.24)
project(DT046_L2)

set(CMAKE_CXX_STANDARD 17)

add_executable(L2 main.cpp comp_sorting.h comp_sorting.cpp data_gen.h data_gen.cpp data_reporting.h data_reporting.cpp)
