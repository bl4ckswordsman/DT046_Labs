#include "data_gen.h"
#include "lin_n_bin_search.h"
#include "bin_search_tree.h"
#include "data_reporting.h"
#include <random>

#include "data_gen.h"


int main() {


    const std::string prfx = "../benchmark_results/";


    int n = 10'000;
    //measure_search_perf(prfx + "linear_search.txt", linear_search, gen_primes);
    //measure_search_perf("binary_search.csv", binary_search, gen_primes);

    std::vector<int> samples = {1'000, 1'500, 2'000, 2'500, 3'000, 3'500, 4'000, 4'500, 5'000, 10'000, 12'000, 14'000, 16'000,
                                18'000, 20'000, 30'000, 35'000, 40'000, 45'000, 50'000, 51'000, 52'000, 53'000, 54'000};
    std::vector<std::vector<int>> data(samples.size());
    for (auto i = 0; i < samples.size(); i++) {
        gen_rand(samples[i], data[i]);
    }

    std::vector<int> samples2 = {999, 224, 399, 624, 899, 2499, 4899, 8099, 12099, 14399, 39999, 624999, 675999};
    std::vector<std::vector<int>> data2(samples2.size());
    for (auto i = 0; i < samples2.size(); i++) {
        gen_rand(samples2[i], data2[i]);
    }

/*    std::vector<std::vector<int>> balanced_data(samples.size());
    for (auto i = 0; i < samples.size(); i++) {
        gen_rand((samples[i]*samples[i])-1, balanced_data[i]);
    }*/

    std::vector<int> balanced_samples(2);
    balanced_samples[0] = (1000*1000) - 1;
    balanced_samples[1] = (1500*1500) - 1;

/*    for (auto i = 0; i < samples.size(); i++) {
        balanced_samples[i] =(samples[i]*samples[i]-1);
    }*/

    std::vector<std::vector<int>> balanced_data(balanced_samples.size());
    for (auto i = 0; i < balanced_samples.size(); i++) {
        gen_rand(balanced_samples[i], balanced_data[i]);
    }


    //measure_search_perf3(prfx + "linear_search.txt", linear_search, data);
    //measure_search_perf3(prfx + "binary_search.txt", binary_search_int, data);


    measure_search_perf4(prfx + "binary_tree_search.txt", binary_search_tree, data);
    //measure_search_perf4(prfx + "binary_tree_search.txt", binary_search_tree, balanced_data);
/*    auto root = new Tree_node;
    root = nullptr;
    std::vector<int> prim;
    gen_primes_int(100, prim);
    std::vector<int> rand1;
    gen_rand(100, rand1);
    build_tree(prim, root);
    auto found = binary_search_tree(root, 13);
    if (found != -1) {
        std::cout << "Found: " << found << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
        std::cout << found << std::endl;
    }*/







/*  Linear Search      Binary Search       Binary Tree Search      Hash Table Search
    O(N)               O(logN)             O(logN)                 O(1)                    */

    return 0;
}
