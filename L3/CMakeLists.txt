cmake_minimum_required(VERSION 3.24)
project(DT046G_L3)

set(CMAKE_CXX_STANDARD 17)

add_executable(DT046G_L3 main.cpp data_gen.h data_gen.cpp lin_n_bin_search.h lin_n_bin_search.cpp data_reporting.cpp
        data_reporting.h bin_search_tree.cpp bin_search_tree.h)
