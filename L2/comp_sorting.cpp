//
// Created by amarildo on 2023-04-18.
//

#include "comp_sorting.h"

void insertion_sort(std::vector<int>& vect_in) {
    for (int i = 1; i < vect_in.size(); i++) {
        int key = vect_in[i];
        int j = i - 1;
        while (j >= 0 && vect_in[j] > key) {
            vect_in[j + 1] = vect_in[j];
            j--;
        }
        vect_in[j + 1] = key;
    }
}


