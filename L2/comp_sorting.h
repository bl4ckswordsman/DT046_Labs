//
// Created by amarildo on 2023-04-18.
//

#ifndef DT046_L2_COMP_SORTING_H
#define DT046_L2_COMP_SORTING_H

#include <vector>

/**
 * Sorts a vector of integers using insertion sort.
 * @param vect_in The vector to be sorted.
 * @return The sorted vector. */
void insertion_sort(std::vector<int>& vect_in);

void selection_sort(std::vector<int>& vect_in);

int partition(std::vector<int>& vect_in, int left, int right);

/**
 * Sorts a vector of integers using Hoare's quick sort wth the last element as pivot.
 * @param vect_in The vector to be sorted.
 * @return The sorted vector. */
void r_pivot_quick_sort(std::vector<int>& vect_in, int left, int right);

void r_pivot_quick_sort_test(std::vector<int>& vect_in);

int med3_partition(std::vector<int>& vect_in, int left, int right);

/**
 * Sorts a vector of integers using Hoare's quick sort wth the median of three as pivot.
 * @param vect_in The vector to be sorted.
 * @return The sorted vector. */
void medof3_quick_sort(std::vector<int>& vect_in, int left, int right);

void med3_pivot_quick_sort_test(std::vector<int>& vect_in);



#endif //DT046_L2_COMP_SORTING_H
