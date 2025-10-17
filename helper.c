#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include "fib.c"

// =============== Helper functions ===============

void printSingleRow(ull *row, int size)
{
    for (int i = 0; i <= size; i++)
    {
        printf("%llu ", row[i]);
    }
    printf("\n");
}

double time_function(ull* (*func)(int, ull *), int n, ull *ops, bool print)
{
    // Setup timers
    struct timespec begin, end;
    // Get the time before we start
    clock_gettime(CLOCK_MONOTONIC, &begin);
    ull* row = func(n, ops);
    clock_gettime(CLOCK_MONOTONIC, &end);
    if(print) {
        printSingleRow(row, n);
    }
    free(row);
    return (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
           (end.tv_sec - begin.tv_sec);
}



void help() {
    printf("./fib.out N [Type] [Print Level]\n");
    printf("\tN is the index of fib array, required.\n");
    printf("\t[Type] is 4 for dp and iterative only, 3 for all three, 2 for dynamic programming version, 1 for recursive version, 0 for iterative version, defaults to 3.\n");
    printf("\t[Print Level] leave blank for speed compare only, or print to print row\n");

}

#endif