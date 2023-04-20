//
// Created by amarildo on 2023-04-18.
//

#include "comp_sorting.h"

void insertion_sort(std::vector<int>& vect_in) {

    for (auto curr_idx = 1; curr_idx < vect_in.size(); curr_idx++) {
        auto comp_idx = curr_idx;
        while (comp_idx > 0 && vect_in[comp_idx] < vect_in[comp_idx - 1]) {
            std::swap(vect_in[comp_idx], vect_in[comp_idx - 1]);
            comp_idx--;
        }
    }
}


