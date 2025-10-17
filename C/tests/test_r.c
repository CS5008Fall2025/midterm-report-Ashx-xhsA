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
    test_a_number(data1,fibr);
    test_a_number(data2,fibr);
    test_a_number(data3,fibr);
    test_a_number(data4,fibr);
    // test_a_number(data5,fibr);
    // test_a_number(data6,fibr);

    
    printf("======Test array======\n");
    test_fib_array(data1,fibr_full);
    test_fib_array(data2,fibr_full);
    test_fib_array(data3,fibr_full);
    test_fib_array(data4,fibr_full);
    // test_fib_array(data5,fibr_full);
    // test_fib_array(data6,fibr_full);

    return 0;
}