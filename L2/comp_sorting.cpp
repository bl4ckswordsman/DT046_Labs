//
// Created by amarildo on 2023-04-18.
//

#include "comp_sorting.h"

void insertion_sort(std::vector<int>& vect_in) {
    for (int curr_idx = 1; curr_idx < vect_in.size(); curr_idx++) {
        // Insert vect_in[curr_idx] into the sorted sequence vect_in[0..curr_idx-1]
        int curr_val = vect_in[curr_idx];
        int prev_idx = curr_idx - 1;
        while (prev_idx >= 0 && vect_in[prev_idx] > curr_val) {
            vect_in[prev_idx + 1] = vect_in[prev_idx];
            prev_idx--;
        }
        // Insert the current value at the correct position
        vect_in[prev_idx + 1] = curr_val;
    }
}

void selection_sort(std::vector<int>& vect_in) {
    for (int curr_idx = 0; curr_idx < vect_in.size() - 1; curr_idx++) {
        // Find the minimum element in unsorted array
        int min_idx = curr_idx;
        for (int j = curr_idx + 1; j < vect_in.size(); j++)
            if (vect_in[j] < vect_in[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        int temp = vect_in[min_idx];
        vect_in[min_idx] = vect_in[curr_idx];
        vect_in[curr_idx] = temp;
    }

}


