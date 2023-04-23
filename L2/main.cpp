
#include "comp_sorting.h"
#include "data_reporting.h"
#include "data_gen.h"



int main() {

        // Insertion sort
    measure_sort_perf("insert_sort_rand.txt", insertion_sort, rand_gen_in_vect);
    measure_sort_perf("insert_sort_const.txt", insertion_sort, const_gen_in_vect);
    measure_sort_perf("insert_sort_monot_incr.txt", insertion_sort, monot_incr_gen_in_vect);
    measure_sort_perf("insert_sort_monot_decr.txt", insertion_sort, monot_decr_gen_in_vect);

    // Selection sort





    return 0;
}




