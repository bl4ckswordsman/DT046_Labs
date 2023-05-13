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

/*  OLD METHOD */
 /* void measure_search_perf3(const std::string &filename, int (*search_func)(std::vector<int> &, int),
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

}*/

// METHOD 1: making a suitable number of searches and dividing the result by the number of searches
void measure_search_perf3(const std::string &filename, int (*search_func)(std::vector<int> &, int),
                          std::vector<std::vector<int>> &data_to_search_vect) {
    std::ofstream out_file(filename);
    std::cout << filename << std::endl;
    out_file << std::left << std::setw(15) << "N" << std::setw(15) << "T[ms]" << std::setw(15) << "Stdev[ms]"
             << std::setw(15) << "Samples" << "\n";
    const int samp_num = 50;

    std::vector<double> stdevs;
    std::vector<double> means;
    for (auto vect: data_to_search_vect) {
        std::vector<double> times;
        std::vector<int> primes;
        gen_primes_int(vect.size(), primes);
        for (auto it = 0; it < samp_num; it++) {

            const int num_searches = 1000;
            std::vector<int> search_values(num_searches);
            std::vector<int> results(num_searches);

            // Generate random search values
            for (auto &search_val: search_values) {
                search_val = vect[rand() % vect.size()];
            }

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < num_searches; i++) {
                results[i] = search_func(primes, search_values[i]);
            }
            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = end - start;


            // Store the elapsed time of each search
            for (int i = 0; i < num_searches; i++) {
                times.push_back(elapsed.count());
            }
            double mean_per_val = elapsed.count() / results.size();
            times.push_back(mean_per_val);

        }
        double mean = std::accumulate(times.begin(), times.end(), 0.0) / times.size();
        double stdev = calculate_stdev(times, mean);
        out_file << std::left << std::setw(15) << vect.size() << std::setw(15) << mean << std::setw(15) << stdev
                 << std::setw(15) << times.size() << std::endl;
        std::cout << "N: " << vect.size() << " mean: " << mean << " stdev: " << stdev << std::endl;

    }
}

// METHOD 2: searching for a fixed time period and then calculating the average search time per value
/*void measure_search_perf3(const std::string &filename, int (*search_func)(std::vector<int> &, int),
                          std::vector<std::vector<int>> &data_to_search_vect) {
    std::ofstream out_file(filename);
    std::cout << filename << std::endl;
    out_file << std::left << std::setw(15) << "N" << std::setw(15) << "T[ms]" << std::setw(15) << "Stdev[ms]"
             << std::setw(15) << "Samples" << "\n";
    const int samp_num = 10;

    std::vector<double> stdevs;
    std::vector<double> means;
    for (auto vect : data_to_search_vect) {
        std::vector<double> times;
        std::vector<int> primes;
        gen_primes_int(vect.size(), primes);
        for (auto i = 0; i < samp_num; i++) {
            std::vector<int> results;
            auto start = std::chrono::high_resolution_clock::now();

            const double search_time = 0.5; // search for 1 second

            while (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count() < search_time) {
                results.push_back(search_func(primes, vect[rand() % vect.size()]));
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            double mean_per_val = elapsed.count() / results.size();
            times.push_back(mean_per_val);
        }
        double mean = std::accumulate(times.begin(), times.end(), 0.0) / times.size();
        double stdev = calculate_stdev(times, mean);
        out_file << std::left << std::setw(15) << vect.size() << std::setw(15) << mean << std::setw(15) << stdev
                 << std::setw(15) << times.size() << std::endl;
        std::cout << "N: " << vect.size() << " mean: " << mean << " stdev: " << stdev << std::endl;
    }
}*/




