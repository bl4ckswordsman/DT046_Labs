//
// Created by amarildo on 2023-04-21.
//

#ifndef DT046_L2_TIME_MEASUREMENT_H
#define DT046_L2_TIME_MEASUREMENT_H

#include <vector>
#include <chrono>
#include <cmath>

double measure_time(void (*func)(std::vector<int>&), std::vector<int>& data, int num_trials);

double measure_stdev(void (*func)(std::vector<int>&), std::vector<int>& data, int num_trials);


#endif //DT046_L2_TIME_MEASUREMENT_H
