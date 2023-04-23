//
// Created by amarildo on 2023-04-21.
//

#ifndef DT046_L2_DATA_REPORTING_H
#define DT046_L2_DATA_REPORTING_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <functional>


double calculate_stdev(std::vector<double> data, double mean);

void test_sorting(const std::string& filename, const std::function<void(std::vector<int>&)>& sort_fn);

#endif //DT046_L2_DATA_REPORTING_H
