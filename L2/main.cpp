#include <iostream>
#include "comp_sorting.h"

int main() {
    std::vector<int> vect = {5, 6, 3, 2, 8, 100, 0, 1};
    for (auto elem : vect) {
        std::cout << elem << std::endl;
    }
    insertion_sort(vect);
    for (auto elem : vect) {
        std::cout << elem << " ";
    }


    return 0;
}
