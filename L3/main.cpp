#include "data_gen.h"
#include "lin_n_bin_search.h"
#include "bin_search_tree.h"
#include "hash_table.h"
#include "data_reporting.h"
#include <random>

#include "data_gen.h"


int main() {
    const std::string prfx = "../benchmark_results/";


    std::vector<int> samples = {1'000, 1'500, 2'000, 2'500, 3'000, 3'500, 4'000, 4'500, 5'000, 10'000, 12'000, 14'000, 16'000,
                                18'000, 20'000, 30'000, 35'000, 40'000, 45'000, 50'000};
    std::vector<std::vector<int>> data(samples.size());
    for (auto i = 0; i < samples.size(); i++) {
        gen_rand(samples[i], data[i]);
    }



    /*measure_search_perf3(prfx + "linear_search.txt", linear_search, data);
    measure_search_perf3(prfx + "binary_search.txt", binary_search_int, data);
    measure_search_perf4(prfx + "binary_tree_search.txt", binary_search_tree, data);*/

    //measure_search_perf4(prfx + "binary_tree_search.txt", binary_search_tree, balanced_data);

    measure_search_perf5(prfx + "hash_table_search.txt", search_hash_table, data);

    vect_to_hash_table(data[0]);

    std::cout << search_hash_table(1000) << std::endl;





/*  Linear Search      Binary Search       Binary Tree Search      Hash Table Search
    O(N)               O(logN)             O(logN)                 O(1)                    */

    return 0;
}
