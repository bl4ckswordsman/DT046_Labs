//
// Created by amarildo on 2023-04-30.
//

#ifndef L3_DATA_REPORTING_H
#define L3_DATA_REPORTING_H

#include "data_gen.h"
#include "bin_search_tree.h"

#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <chrono>
#include <numeric>
#include <functional>
#include <iomanip>

double calculate_stdev(std::vector<double> data, double mean);

void measure_search_perf3(const std::string& filename, int (*search_func)(std::vector<int>&, int),
                       std::vector<std::vector<int>>& data_to_search_vect);

void measure_search_perf4(const std::string &filename, int (*search_func)(Tree_node*, int),
                          std::vector<std::vector<int>> &data_to_search_vect);

void measure_search_perf5(const std::string &filename, int (*hash_search)(int),
                            std::vector<std::vector<int>> &data_to_search_vect);

void measure_search_perf6(const std::string& filename, int (*search_func)(Tree_node*, int),
                          std::vector<std::vector<int>>& data_to_search_vect, bool use_hash_table);

#endif //L3_DATA_REPORTING_H
