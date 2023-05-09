#include "data_gen.h"
#include "search_alg.h"
#include "data_reporting.h"
#include <iostream>
#include <random>
#include <chrono>





int main() {


    const std::string prfx = "../benchmark_results/";


    int n = 10'000;
    //measure_search_perf(prfx + "linear_search.txt", linear_search, gen_primes);
    //measure_search_perf("binary_search.csv", binary_search, gen_primes);

    std::vector<std::vector<int>> data(5);
    gen_rand(1000, data[0]);
    gen_rand(5'000, data[1]);
    gen_rand(10'000, data[2]);
    gen_rand(20'000, data[3]);
    gen_rand(50'000, data[4]);

    measure_search_perf3(prfx + "linear_search.txt", linear_search_int, data);
    measure_search_perf3(prfx + "binary_search.txt", binary_search_int, data);




    return 0;
}
