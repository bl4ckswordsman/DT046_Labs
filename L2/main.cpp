#include <iostream>
#include "comp_sorting.h"
#include "data_gen.h"

int main() {
    std::vector<int> vect;
    rand_gen_in_vect(10, vect);
    for (auto elem : vect) {
        std::cout << elem << std::endl;
    }
    insertion_sort(vect);
    for (auto elem : vect) {
        std::cout << elem << " ";
    }


    return 0;
}
