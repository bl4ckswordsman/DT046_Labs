//
// Created by amarildo on 2023-04-30.
//


#include "data_reporting.h"
#include "data_gen.h"

double calculate_stdev(std::vector<double> data, double mean) {
    double sum = 0;
    for (auto i = 0; i < data.size(); i++) {
        sum += pow(data[i] - mean, 2);
    }
    return sqrt(sum / data.size());
}

void measure_search_perf3(const std::string &filename, int (*search_func)(std::vector<int> &, int),
                        std::vector<std::vector<int>> &data_to_search_vect) {
    std::ofstream out_file(filename);
    std::cout << filename << std::endl;
    out_file << std::left << std::setw(15) << "N" << std::setw(15) << "T[ms]" << std::setw(15) << "Stdev[ms]"
             << std::setw(15) << "Samples" << "\n";
    const int samp_num = 15;

    std::vector<double> stdevs;
    std::vector<double> means;
    for (auto vect : data_to_search_vect) {
        std::vector<double> times;
        std::vector<int> primes;
        gen_primes_int(vect.size(), primes);
        for (auto i = 0; i < samp_num; i++) {
            std::vector<int> results;
            auto start = std::chrono::high_resolution_clock::now();
            for (auto j : vect) {
                results.push_back(search_func(primes, j));
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            times.push_back(elapsed.count());
        }
        double mean = std::accumulate(times.begin(), times.end(), 0.0) / times.size();
        double stdev = calculate_stdev(times, mean);
        out_file << std::left << std::setw(15) << vect.size() << std::setw(15) << mean << std::setw(15) << stdev
                 << std::setw(15) << times.size() << std::endl;
        std::cout << "N: " << vect.size() << " mean: " << mean << " stdev: " << stdev << std::endl;
    }

}


