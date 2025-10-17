#ifndef HELPER_C
#define HELPER_C

#include "fib.c"

// =============== Helper functions ===============


// print an array of fib numbers.
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


// Helper function to main function
void help() {
    printf("./fib.out N [Type] [Print Level]\n");
    printf("\tN is the index of fib array, required.\n");
    printf("\t[Type] is 4 for dp and iterative only, 3 for all three, 2 for dynamic programming version, 1 for recursive version, 0 for iterative version, defaults to 3.\n");
    printf("\t[Print Level] leave blank for speed compare only, or print to print row\n");

}

// test single dynamic programming fib function
void test_a_number(int n, ull (*func)(int, ull *)){
    ull ops = 0;
    printf("fib%d is %llu, operations taken: %llu\n",
        n,func(n,&ops),ops);
    
    // initiate table if the function is dynamic programming
    if(func == fibdp){
        table_init();
    }

    }
void test_fib_array(int n, ull* (*func)(int, ull *)){
    ull ops = 0;
    printf("n = %d\n",n);
    double time = time_function(func,n,&ops, 1);
    
    printf("time: %f operation taken: %llu\n", time, ops);}

#endif