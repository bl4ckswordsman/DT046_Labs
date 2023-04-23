//
// Created by amarildo on 2023-04-23.
//

#include "data_reporting.h"
#include "data_gen.h"


double calculate_stdev(std::vector<double> data, double mean) {
    double sum = 0;
    for (auto& d : data) {
        sum += pow(d - mean, 2);
    }
    return sqrt(sum / data.size());
}


// Test a sorting function and write the results to a file
void measure_sort_perf(const std::string &filename, void (*sorting_func)(std::vector<int> &),
                       void (*gen_func)(int, std::vector<int> &)) {
    std::ofstream out_file(filename);
    std::string title = filename.substr(0, filename.size()-4);
    out_file << "Sorting performance - " << title << "\n";
    out_file << std::left << std::setw(15) << "N" << std::setw(15) << "T[ms]" << std::setw(15) << "Stdev[ms]"
             << std::setw(15) << "Samples" << "\n";

    const int samp1 = 2000;
    const int samp2 = 8000;
    const int samp3 = 12000;
    const int samp4 = 50000;
    const int samp5 = 100000;

    const int samp_num = 5;

    std::vector<int> ns{samp1, samp2, samp3, samp4, samp5};

    for (auto& n : ns) {
        std::vector<double> times(samp_num);

        for (int j = 0; j < samp_num; ++j) {
            std::vector<int> v;
            gen_func(n, v);

            auto start_time = std::chrono::high_resolution_clock::now();
            sorting_func(v);
            auto end_time = std::chrono::high_resolution_clock::now();

            auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
            times[j] = duration_ms / static_cast<double>(1000);
        }

        double mean_time_ms = std::accumulate(times.begin(), times.end(), 0.0) / times.size();
        double stdev_ms = calculate_stdev(times, mean_time_ms);

        out_file << std::left << std::setw(15) << n << std::setw(15) << mean_time_ms << std::setw(15)
                 << stdev_ms << std::setw(15) << times.size() << "\n";

        std::cout << "n: " << n << ", mean time: " << mean_time_ms << ", stdev: " << stdev_ms << "\n";

        out_file.flush();
    }

    out_file.close();
}

