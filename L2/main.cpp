
#include "comp_sorting.h"
#include "data_reporting.h"
#include "data_gen.h"



int main() {

        // Insertion sort
    /*measure_sort_perf("insert_sort_rand.txt", insertion_sort, rand_gen_in_vect);
    measure_sort_perf("insert_sort_const.txt", insertion_sort, const_gen_in_vect);
    measure_sort_perf("insert_sort_monot_incr.txt", insertion_sort, monot_incr_gen_in_vect);
    measure_sort_perf("insert_sort_monot_decr.txt", insertion_sort, monot_decr_gen_in_vect);*/

        // Selection sort
    /*measure_sort_perf("select_sort_rand.txt", selection_sort, rand_gen_in_vect);
    measure_sort_perf("select_sort_const.txt", selection_sort, const_gen_in_vect);
    measure_sort_perf("select_sort_monot_incr.txt", selection_sort, monot_incr_gen_in_vect);
    measure_sort_perf("select_sort_monot_decr.txt", selection_sort, monot_decr_gen_in_vect);*/

    // Hoare right-pivot quick sort
    measure_sort_perf("right_pivot_quick_sort_rand.txt", r_pivot_quick_sort_test,
                      rand_gen_in_vect);
    measure_sort_perf("right_pivot_quick_sort_const.txt", r_pivot_quick_sort_test,
                      const_gen_in_vect);
    measure_sort_perf("right_pivot_quick_sort_monot_incr.txt", r_pivot_quick_sort_test,
                      monot_incr_gen_in_vect);
    measure_sort_perf("right_pivot_quick_sort_monot_decr.txt", r_pivot_quick_sort_test,
                      monot_decr_gen_in_vect);

    // Hoare median-of-three quick sort
    /*measure_sort_perf("medof3_quick_sort_rand.txt", med3_pivot_quick_sort_test,
                      rand_gen_in_vect);
    measure_sort_perf("medof3_quick_sort_const.txt", med3_pivot_quick_sort_test,
                        const_gen_in_vect);
    measure_sort_perf("medof3_quick_sort_monot_incr.txt", med3_pivot_quick_sort_test,
                        monot_incr_gen_in_vect);
    measure_sort_perf("medof3_quick_sort_monot_decr.txt", med3_pivot_quick_sort_test,
                        monot_decr_gen_in_vect);*/

    // std::sort
    /*measure_std_sort_perf("std_sort_rand.txt", rand_gen_in_vect);
    measure_std_sort_perf("std_sort_const.txt", const_gen_in_vect);
    measure_std_sort_perf("std_sort_monot_incr.txt", monot_incr_gen_in_vect);
    measure_std_sort_perf("std_sort_monot_decr.txt", monot_decr_gen_in_vect);*/


    /*Algorithm                     Random      Constant        Increasing      Decreasing
    Insertion Sort                  O(n^2)      O(n)            O(n^2)          O(n^2)
    Selection Sort                  O(n^2)      O(n^2)          O(n^2)          O(n^2)
    Quicksort (Right Pivot)         O(n^2)      O(n*log(n))     O(n^2)          O(n^2)
    Quicksort (Median of 3 Pivot)   O(n*log(n)) O(n*log(n))     O(n*log(n))     O(n*log(n))
    std::sort                       O(n*log(n)) O(n*log(n))     O(n*log(n))     O(n*log(n)) */



    return 0;
}




