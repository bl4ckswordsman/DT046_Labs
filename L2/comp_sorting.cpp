//
// Created by amarildo on 2023-04-18.
//

#include <algorithm>
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
        int pivot = vect_in[right];
        int pivot_idx = partition(vect_in, left, right, pivot);
        r_pivot_quick_sort(vect_in, left, pivot_idx - 1);
        r_pivot_quick_sort(vect_in, pivot_idx + 1, right);
    }

}



/*int partition(std::vector<int> &vect_in, int low, int high, int pivot) {
    int i = low - 1; // index of smaller element
    for (int j = low; j <= high - 1; j++) {
        if (vect_in[j] <= pivot) {
            i++;  // increment index of smaller element
            std::swap(vect_in[i], vect_in[j]);
        }
    }
    // Place pivot at its correct position
    std::swap(vect_in[i + 1], vect_in[high]);
    return i + 1;
}*/

int partition(std::vector<int> &vect_in, int low, int high, int pivot) {
    int i = low - 1, j = high; // initialize i and j
    while (true) {
        while (vect_in[++i] < pivot); // increment i until vect_in[i] >= pivot
        while (j > low && vect_in[--j] > pivot); // decrement j until vect_in[j] <= pivot or j == low
        if (i >= j) break; // if i and j cross or meet, break
        std::swap(vect_in[i], vect_in[j]); // swap vect_in[i] and vect_in[j]
    }
    // Place pivot at its correct position
    std::swap(vect_in[i], vect_in[high]);
    return i;
}

/* ALTERNATIVE
while (true) {
// Increment i until vect_in[i] is greater than or equal to pivot
while (vect_in[++i] < pivot);

// Decrement j until vect_in[j] is less than or equal to pivot
while (j > low && vect_in[--j] > pivot);

if (i >= j) {
// If i and j cross or meet, break the loop
break;
}

// Swap vect_in[i] and vect_in[j]
std::swap(vect_in[i], vect_in[j]);
}

// Place pivot at its correct position
std::swap(vect_in[i], vect_in[high]);

return i;
*/


int partition_m3(std::vector<int> &vect_in, int low, int high, int pivot) {
    int i = low, j = high;
    while (i <= j) {
        while (vect_in[i] < pivot) i++;
        while (vect_in[j] > pivot) j--;
        if (i <= j) {
            std::swap(vect_in[i], vect_in[j]);
            i++;
            j--;
        }
    }
    return i;
}


void r_pivot_quick_sort_test(std::vector<int> &vect_in) {
    r_pivot_quick_sort(vect_in, 0, vect_in.size() - 1);
}


void m3_piv_quick_sort(std::vector<int> &vect_in, int low, int high) {
    if (low < high) {
        // Find median_of_3 of vect_in[low], vect_in[high] and vect_in[(low + high) / 2]
        int mid = (low + high) / 2;
        int pivot = median_of_3(vect_in[low], vect_in[mid], vect_in[high]);

        // Partition the vector around the pivot
        int pi = partition_m3(vect_in, low, high, pivot);

        // Recursively sort left and right halves
        m3_piv_quick_sort(vect_in, low, pi - 1);
        m3_piv_quick_sort(vect_in, pi, high);
    }
}

int median_of_3(int a, int b, int c) {
    if (a <= b && b <= c) return b;
    if (c <= b && b <= a) return b;
    if (b <= a && a <= c) return a;
    if (c <= a && a <= b) return a;
    return c;
}



void med3_quick_sort_test(std::vector<int> &vect_in) {
    m3_piv_quick_sort(vect_in, 0, vect_in.size() - 1);
}

void std_sort_test(std::vector<int> &vect_in) {
    std::sort(vect_in.begin(),vect_in.end());
}







