//
// Created by amarildo on 2023-04-30.
//
#include "search_alg.h"


int linear_search(std::vector<bool> &vect, int target) {
    for (int i = 2; i < vect.size(); i++) {
        if (vect[i] == true && i == target)
            return i;
    }
    return -1;
}

int binary_search(std::vector<bool> &vect, int target) {
    int low = 0;
    int high = vect.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (vect[mid] == target)
            return mid;
        else if (vect[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

