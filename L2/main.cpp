#include <iostream>
#include <fstream>
#include <iomanip>
#include "comp_sorting.h"
#include "data_gen.h"
#include "time_measurement.h"

double calculate_stdev(std::vector<double> data, double mean) {
    double sum = 0;
    for (auto& d : data) {
        sum += pow(d - mean, 2);
    }
    return sqrt(sum / data.size());
}

int main() {
    std::ofstream out_file("table.txt");
    //out_file << "N\tT[ms]\tStdev[ms]\tSamples\n";
    out_file << "Insertion sort\n";
    out_file << std::left << std::setw(15) << "N" << std::setw(15) << "T[ms]" << std::setw(15) << "Stdev[ms]"
            << std::setw(15) << "Samples" << "\n";

    std::vector<int> ns{2000, 8000, 12000, 50000, 100000};

    for (auto& n : ns) {
        std::vector<double> times(5);

        for (int j = 0; j < 5; ++j) {
            std::vector<int> v;
            rand_gen_in_vect(n, v);

            auto start_time = std::chrono::high_resolution_clock::now();
            insertion_sort(v);
            auto end_time = std::chrono::high_resolution_clock::now();

            auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
            times[j] = duration_ms / static_cast<double>(1000);
        }

        double mean_time_ms = std::accumulate(times.begin(), times.end(), 0.0) / times.size();
        double stdev_ms = calculate_stdev(times, mean_time_ms);


        //out_file << n << "\t" << mean_time_ms << "\t" << stdev_ms << "\t" << times.size() << "\n";
        out_file << std::left << std::setw(15) << n << std::setw(15) << mean_time_ms << std::setw(15)
                << stdev_ms << std::setw(15) << times.size() << "\n";

        // print results
        std::cout << "n: " << n << ", mean time: " << mean_time_ms << ", stdev: " << stdev_ms << "\n";

        // write results to file
        out_file.flush();
    }

    out_file.close();


    return 0;
}




