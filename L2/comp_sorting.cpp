//
// Created by amarildo on 2023-04-18.
//

#include "comp_sorting.h"

void insertion_sort(std::vector<int>& vect_in) {
    for (int curr_idx = 1; curr_idx < vect_in.size(); curr_idx++) {
        int curr_val = vect_in[curr_idx];
        int prev_idx = curr_idx - 1;
        while (prev_idx >= 0 && vect_in[prev_idx] > curr_val) {
            vect_in[prev_idx + 1] = vect_in[prev_idx];
            prev_idx--;
        }
        vect_in[prev_idx + 1] = curr_val;
    }
}


