//
// Created by amarildo on 2023-04-21.
//

#include "time_measurement.h"

double measure_time(void (*func)(std::vector<int>&), std::vector<int>& data, int num_trials)
{
    // Define variable for timing
    double total_time = 0;

    // Loop over trials
    for (int j = 0; j < num_trials; j++)
    {
        // Copy data to new vector for sorting
        std::vector<int> sorted_data(data);

        // Start timer
        auto start_time = std::chrono::high_resolution_clock::now();

        // Call function to be timed
        func(sorted_data);

        // Stop timer and calculate elapsed time
        auto end_time = std::chrono::high_resolution_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

        // Update variable for timing
        total_time += elapsed_time;
    }

    // Calculate average time
    double avg_time = total_time / num_trials;

    return avg_time;
}

double measure_stdev(void (*func)(std::vector<int>&), std::vector<int>& data, int num_trials)
{
    // Define variable for timing
    double total_time_squared = 0;

    // Loop over trials and compute total_time_squared
    for (int j = 0; j < num_trials; j++)
    {
        // Copy data to new vector for sorting
        std::vector<int> sorted_data(data);

        // Start timer
        auto start_time = std::chrono::high_resolution_clock::now();

        // Call function to be timed
        func(sorted_data);

        // Stop timer and calculate elapsed time
        auto end_time = std::chrono::high_resolution_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

        // Update variable for timing
        total_time_squared += pow(elapsed_time - measure_time(func, sorted_data, 1), 2);
    }

    // Calculate standard deviation
    double stdev_time = sqrt(total_time_squared / num_trials);

    return stdev_time;
}

