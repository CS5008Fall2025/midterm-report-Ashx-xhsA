// Code Frame from Sort Homework 

#include <stdio.h>  // Include file for standard input/output
#include <stdlib.h> // so we can use atoi()
#include <time.h>   // so we can use time_t and clock_gettime()

#include "fib.c"
#include "helper.c"


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
    test_a_number(data1,fibdp);
    test_a_number(data2,fibdp);
    test_a_number(data3,fibdp);
    test_a_number(data4,fibdp);
    // test_a_number(data5,fibdp);
    // test_a_number(data6,fibdp);

    
    printf("======Test array======\n");
    test_fib_array(data1,fibdp_full);
    test_fib_array(data2,fibdp_full);
    test_fib_array(data3,fibdp_full);
    test_fib_array(data4,fibdp_full);
    // test_fib_array(data5,fibdp_full);
    // test_fib_array(data6,fibdp_full);

    return 0;
}