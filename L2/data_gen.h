//
// Created by amarildo on 2023-04-19.
//

#ifndef DT046_L2_DATA_GEN_H
#define DT046_L2_DATA_GEN_H

#include <vector>
#include <random>

/**
 * Generates a vector of random integers.
 * @param n The number of elements in the vector.
 * @param vect_out The vector to be filled with random integers. */
void rand_gen_in_vect(int n, std::vector<int>& vect_out);
/**
 * Generates a vector of monotonically increasing integers.
 * @param n The number of elements in the vector.
 * @param vect_out The vector to be filled with monotonically increasing integers. */
void monot_incr_gen_in_vect(int n, std::vector<int>& vect_out);
/**
 * Generates a vector of monotonically decreasing integers.
 * @param n The number of elements in the vector.
 * @param vect_out The vector to be filled with monotonically decreasing integers. */
void monot_decr_gen_in_vect(int n, std::vector<int>& vect_out);
/**
 * Generates a vector of constant integers.
 * @param n The number of elements in the vector.
 * @param vect_out The vector to be filled with constant integers. */
void const_gen_in_vect(int n, std::vector<int>& vect_out);


#endif //DT046_L2_DATA_GEN_H
