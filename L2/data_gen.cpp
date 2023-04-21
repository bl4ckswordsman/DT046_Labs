//
// Created by amarildo on 2023-04-19.
//
#include "data_gen.h"

void rand_gen_in_vect(int n, std::vector<int> &vect_out) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, n);
    for (auto i = 0; i < n; i++) {
        vect_out.push_back(dis(gen));
    }
}

