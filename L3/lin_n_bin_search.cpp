//
// Created by amarildo on 2023-04-30.
//
#include <iostream>
#include <queue>
#include "lin_n_bin_search.h"

int linear_search(std::vector<int> &vect, int target) {
    for (int i = 2; i < vect.size(); i++) {
        if (vect[i] == target)
            return i;
    }
    return -1;
}


int binary_search_int(std::vector<int> &vect, int target) {
    int low = 0;
    int high = vect.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (vect[mid] == target) {
            return mid;
        } else if (vect[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}






