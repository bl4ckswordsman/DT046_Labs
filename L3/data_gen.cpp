//
// Created by amarildo on 2023-04-30.
//
#include <random>
#include "data_gen.h"


void gen_primes_bool(int n, std::vector<bool> &vect) {
    vect[0] = false;
    vect[1] = false;
    int i = 2;
    while (i < n/2) {
        int divisor = i * 2;
        while (divisor < n) {
            vect[divisor] = false;
            divisor += i;
        }
        i++;
        while (vect[i] == false)
            i++;
    }
}


void gen_rand(int n, std::vector<int> &vect) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, n);
    vect.resize(n);
    for (int i = 0; i < n; i++) {
        vect[i] = dis(gen);
    }
}

void gen_primes_int(int n, std::vector<int> &vect) {
    std::vector<bool> vect_bool(n * 10, true); // Increase the size of vect_bool to ensure enough primes are generated
    gen_n_primes_bool(n, vect_bool);

    for (int i = 0; i < vect_bool.size(); i++) {
        if (vect_bool[i]) {
            vect.push_back(i);
        }
        if (vect.size() == n) {
            break;
        }
    }
    vect.resize(n); // Resize vect to contain exactly n prime numbers
}

void gen_n_primes_bool(int n, std::vector<bool> &vect) {
    vect[0] = false;
    vect[1] = false;
    int count = 0;
    int i = 2;
    while (count < n) {
        if (vect[i]) {
            count++;
            for (int j = i * 2; j < vect.size(); j += i) {
                vect[j] = false;
            }
        }
        i++;
    }

}
