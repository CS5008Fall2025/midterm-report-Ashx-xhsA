// Code Frame from Sort Homework 

#include <stdio.h>  // Include file for standard input/output
#include <stdlib.h> // so we can use atoi()
#include <time.h>   // so we can use time_t and clock_gettime()

#include "../src/fib.c"
#include "../src/helper.c"


// =============== Main Functions ===============
int main(int argc, char *argv[])
{

    // Some test data sets.
    int data1 = 0;
    int data2 = 1;
    int data3 = 10;
    int data4 = 20;
    int data5 = 100;
    int data6 = 1000;

    int print = 1;


    printf("======Test single number======\n");
    test_a_number(data1,fibi);
    test_a_number(data2,fibi);
    test_a_number(data3,fibi);
    test_a_number(data4,fibi);
    // test_a_number(data5,fibi);
    // test_a_number(data6,fibi);

    
    printf("======Test array======\n");
    test_fib_array(data1,fib_iterative);
    test_fib_array(data2,fib_iterative);
    test_fib_array(data3,fib_iterative);
    test_fib_array(data4,fib_iterative);
    // test_fib_array(data5,fib_iterative);
    // test_fib_array(data6,fib_iterative);

    return 0;
}