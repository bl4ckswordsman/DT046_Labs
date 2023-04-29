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

std::string get_title(const std::string& txt_file);

/**
 * Test a sorting function and write the results to a file.
 * @param filename The name of the file to write to.
 * @param sorting_func The sorting function to test.
 * @param gen_func The function to generate the data to be sorted. */
void measure_sort_perf(const std::string& filename, void (*sorting_func)(std::vector<int>&),
                       void (*gen_func)(int, std::vector<int>&));


#endif //DT046_L2_DATA_REPORTING_H
