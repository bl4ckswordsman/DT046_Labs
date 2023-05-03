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

/*int partition(std::vector<int> &vect_in, int low, int high, int pivot) {
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
}*

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

/* OLDER ALTERNATIVE

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

*/


int partition_m3(std::vector<int> &vect_in, int low, int high, int pivot) {
    int i = low - 1, j = high + 1;
    while (true) {
        do {
            i++;
        } while (vect_in[i] < pivot);
        do {
            j--;
        } while (vect_in[j] > pivot);
        if (i >= j) {
            return j;
        }
        std::swap(vect_in[i], vect_in[j]);
    }
}


void r_pivot_quick_sort_test(std::vector<int> &vect_in) {
    r_pivot_quick_sort(vect_in, 0, vect_in.size() - 1);
}

int median_of_3(int a, int b, int c) {
    if (a <= b && b <= c) return b;
    if (c <= b && b <= a) {
        std::swap(a, c);
        return b;
    }
    if (b <= a && a <= c) {
        std::swap(a, b);
        return b;
    }
    if (c <= a && a <= b) {
        std::swap(a, c);
        std::swap(b, c);
        return b;
    }
    std::swap(a, b);
    if (c <= b) {
        std::swap(b, c);
        if (a <= b) {
            return b;
        }
        std::swap(a, b);
        return b;
    }
    return b;
}


int median_of_3(std::vector<int> &vect_in, int low, int high) {
    int mid = low + (high - low) / 2;
    if (vect_in[low] > vect_in[high]) {
        std::swap(vect_in[low], vect_in[high]);
    }
    if (vect_in[mid] < vect_in[low]) {
        std::swap(vect_in[mid], vect_in[low]);
    }
    if (vect_in[high] < vect_in[mid]) {
        std::swap(vect_in[high], vect_in[mid]);
    }
    // arr[low] <= arr[mid] <= arr[high]
    return vect_in[mid];
}

void m3_piv_quick_sort(std::vector<int> &vect_in, int low, int high) {

    if (low < high) {
        // Find median_of_3 of vect_in[low], vect_in[high] and vect_in[(low + high) / 2]
        int mid = (low + high) / 2;
        int pivot = median_of_3(vect_in[low], vect_in[mid], vect_in[high]);

        // Partition the vector around the pivot using Hoare partition scheme
        int pi = partition_m3(vect_in, low, high, pivot);

        // Recursively sort left and right halves
        m3_piv_quick_sort(vect_in, low, pi);
        m3_piv_quick_sort(vect_in, pi + 1, high);
    }
/*
    if (low < high) {
        // Find median of 3
        int pivot = median_of_3(vect_in, low, high);

        // Partition vector around pivot using Hoare's partitioning scheme
        int p = partition_m3(vect_in, low, high, pivot);

        // Recursively sort left and right sub-arrays
        m3_piv_quick_sort(vect_in, low, p);
        m3_piv_quick_sort(vect_in, p + 1, high);
    }*/
}





void med3_quick_sort_test(std::vector<int> &vect_in) {
    m3_piv_quick_sort(vect_in, 0, vect_in.size() - 1);
}

void std_sort_test(std::vector<int> &vect_in) {
    std::sort(vect_in.begin(),vect_in.end());
}







