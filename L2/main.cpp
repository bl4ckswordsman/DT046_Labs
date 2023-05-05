
#include "comp_sorting.h"
#include "data_reporting.h"
#include "data_gen.h"



int main() {
    const std::string prfx = "../Test_results/"; // Prefix for the output files

/*
        // Insertion sort
    measure_sort_perf(prfx + "insert_sort_rand.txt", insertion_sort, rand_gen_in_vect);
    measure_sort_perf(prfx + "insert_sort_const.txt", insertion_sort, const_gen_in_vect);
    measure_sort_perf(prfx + "insert_sort_monot_incr.txt", insertion_sort, monot_incr_gen_in_vect);
    measure_sort_perf(prfx + "insert_sort_monot_decr.txt", insertion_sort, monot_decr_gen_in_vect);

        // Selection sort
    measure_sort_perf(prfx + "select_sort_rand.txt", selection_sort, rand_gen_in_vect);
    measure_sort_perf(prfx + "select_sort_const.txt", selection_sort, const_gen_in_vect);
    measure_sort_perf(prfx + "select_sort_monot_incr.txt", selection_sort, monot_incr_gen_in_vect);
    measure_sort_perf(prfx + "select_sort_monot_decr.txt", selection_sort, monot_decr_gen_in_vect);

    // Hoare right-pivot quick sort
    measure_sort_perf(prfx + "right_pivot_quick_sort_rand.txt", r_pivot_quick_sort_test,
                      rand_gen_in_vect);
    measure_sort_perf(prfx + "right_pivot_quick_sort_const.txt", r_pivot_quick_sort_test,
                      const_gen_in_vect);
    measure_sort_perf(prfx + "right_pivot_quick_sort_monot_incr.txt", r_pivot_quick_sort_test,
                      monot_incr_gen_in_vect);
    measure_sort_perf(prfx + "right_pivot_quick_sort_monot_decr.txt", r_pivot_quick_sort_test,
                      monot_decr_gen_in_vect);

    // Hoare median_of_3-of-three quick sort
    measure_sort_perf(prfx + "medof3_quick_sort_rand.txt", med3_quick_sort_test,
                      rand_gen_in_vect);
    measure_sort_perf(prfx + "medof3_quick_sort_const.txt", med3_quick_sort_test,
                      const_gen_in_vect);
    measure_sort_perf(prfx + "medof3_quick_sort_monot_incr.txt", med3_quick_sort_test,
                      monot_incr_gen_in_vect);
    measure_sort_perf(prfx + "medof3_quick_sort_monot_decr.txt", med3_quick_sort_test,
                      monot_decr_gen_in_vect);



    // std::sort
    measure_sort_perf(prfx + "std_sort_rand.txt", std_sort_test,
                      rand_gen_in_vect);
    measure_sort_perf(prfx + "std_sort_const.txt", std_sort_test,
                        const_gen_in_vect);
    measure_sort_perf(prfx + "std_sort_monot_incr.txt", std_sort_test,
                        monot_incr_gen_in_vect);
    measure_sort_perf(prfx + "std_sort_monot_decr.txt", std_sort_test,
                        monot_decr_gen_in_vect);

*/



    /*Algorithm                     Random      Constant        Increasing      Decreasing
    Insertion Sort                  O(n^2)      O(n)            O(n)            O(n^2)
    Selection Sort                  O(n^2)      O(n^2)          O(n^2)          O(n^2)
    Quicksort (Right Pivot)         O(n*log(n)) O(n^2)          O(n^2)          O(n^2)          Rand-quicker
    Quicksort (Median of 3 Pivot)   O(n*log(n)) O(n*log(n))     O(n*log(n))     O(n*log(n))
    std::sort                       O(n*log(n)) O(n*log(n))     O(n*log(n))     O(n*log(n)) */


    return 0;
}




