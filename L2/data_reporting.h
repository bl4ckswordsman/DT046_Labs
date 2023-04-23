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

/**
 * Calculates the mean of a vector of doubles.
 * @param data The vector of doubles.
 * @return The mean of the vector. */
double calculate_stdev(std::vector<double> data, double mean);

/**
 * Calculates the standard deviation of a vector of doubles.
 * @param data The vector of doubles.
 * @param mean The mean of the vector.
 * @return The standard deviation of the vector. */
void measure_sort_perf(const std::string& filename, void (*sorting_func)(std::vector<int>&),
                       void (*gen_func)(int, std::vector<int>&));

#endif //DT046_L2_DATA_REPORTING_H
