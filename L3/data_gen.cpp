//
// Created by amarildo on 2023-04-30.
//
#include "data_gen.h"


void gen_primes(int n, std::vector<bool> &vect) {
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
