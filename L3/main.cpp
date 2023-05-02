#include "data_gen.h"
#include "search_alg.h"
#include <iostream>
#include <random>
#include <chrono>


int main() {
    int n = 10;
    std::vector<bool> vect(n, true);
    gen_primes(n, vect);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> rand_vect;
    std::uniform_int_distribution<> dis(0, n);

    for (auto i = 0; i < n; i++) {
        rand_vect.push_back(dis(gen));
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int i : rand_vect) {

        if (linear_search(vect, i) != -1)
            std::cout << "Found " << i << std::endl;
        else
            std::cout << "Not found " << i << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Linear search elapsed time: " << elapsed_seconds.count() << "s\n";

    std::cout << std::endl;

    std::cout << "Binary search" << std::endl;
    std::vector<int> rand_vect2;
    std::vector<bool> vect2(n, true);
    std::uniform_int_distribution<> dis2(0, n);
    for (auto i = 0; i < n; i++) {
        rand_vect2.push_back(dis2(gen));
    }
    gen_primes(n, vect2);

    auto result = binary_search(vect2, 2);
    std::cout << "Result: " << result << std::endl;




    return 0;
}
