//
// Created by amarildo on 2023-04-30.
//

#ifndef L3_DATA_GEN_H
#define L3_DATA_GEN_H

#include <vector>

/**
 * Generates primes using the Sieve of Eratosthenes.
 * @param n The number of elements in the vector.
 * @param vect The vector to be filled with primes.
 */
void gen_primes_bool(int n, std::vector<bool>& vect);


void gen_primes_int(int n, std::vector<int>& vect);

/**
 * Generates random numbers.
 * @param n The number of elements in the vector.
 * @param vect The vector to be filled with random numbers.
 */
void gen_rand(int n, std::vector<int>& vect);


#endif //L3_DATA_GEN_H
