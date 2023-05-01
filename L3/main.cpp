#include "data_gen.h"
#include <iostream>


int main() {
    std::vector<bool> vect(100, true);
    sieve_of_eratosthenes(100, vect);
    for (int i = 0; i < 100; i++) {
        if (vect[i])
            std::cout << i << " ";
    }
    std::cout << std::endl;



    return 0;
}
