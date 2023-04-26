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

void r_pivot_quick_sort(std::vector<int> &vect_in, int left, int right) {
    if (left < right) {
        int pivot_idx = partition(vect_in, left, right);

        r_pivot_quick_sort(vect_in, left, pivot_idx - 1);
        r_pivot_quick_sort(vect_in, pivot_idx + 1, right);
    }

}

int partition(std::vector<int> &vect_in, int low, int high) {
    int pivot = vect_in[high];  // pivot is the last element in the array
    int i = low - 1;  // index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (vect_in[j] <= pivot) {
            i++;  // increment index of smaller element
            std::swap(vect_in[i], vect_in[j]);
        }
    }

    // Place pivot at its correct position
    std::swap(vect_in[i + 1], vect_in[high]);

    return i + 1;  // return the index of pivot
}



void r_pivot_quick_sort_test(std::vector<int> &vect_in) {
    r_pivot_quick_sort(vect_in, 0, vect_in.size() - 1);
}

int med3_partition(std::vector<int>& vect_in, int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot_idx = right;

    if (vect_in[left] < vect_in[mid]) {
        if (vect_in[mid] < vect_in[right])
            pivot_idx = mid;
        else if (vect_in[left] < vect_in[right])
            pivot_idx = left;
    } else if (vect_in[left] < vect_in[right])
        pivot_idx = left;

    std::swap(vect_in[pivot_idx], vect_in[right]);

    int pivot = vect_in[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (vect_in[j] <= pivot) {
            i++;
            std::swap(vect_in[i], vect_in[j]);
        }
    }

    std::swap(vect_in[i + 1], vect_in[right]);

    return i + 1;
}

void med3_pivot_quick_sort(std::vector<int>& vect_in, int left, int right) {
    if (left < right) {
        int pivot_idx = med3_partition(vect_in, left, right);

        med3_pivot_quick_sort(vect_in, left, pivot_idx - 1);
        med3_pivot_quick_sort(vect_in, pivot_idx + 1, right);
    }
}


void med3_pivot_quick_sort_test(std::vector<int> &vect_in) {
    med3_pivot_quick_sort(vect_in, 0, vect_in.size() - 1);
}







