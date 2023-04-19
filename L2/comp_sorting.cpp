//
// Created by amarildo on 2023-04-18.
//

#include "comp_sorting.h"

void insertion_sort(std::vector<int> vect_in) {
    // i is the index of the element to be inserted and j is the index of the element to be compared to.
    for (auto elem_in_idx = 1; elem_in_idx < vect_in.size(); elem_in_idx++) {
        auto elem_comp_idx = elem_in_idx;
        while (elem_comp_idx > 0 && vect_in[elem_comp_idx] < vect_in[elem_comp_idx - 1]) {
            std::swap(vect_in[elem_comp_idx], vect_in[elem_comp_idx - 1]);
            elem_comp_idx--;
        }
    }
}


