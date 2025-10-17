// Code Frame from Sort Homework 

#include <stdio.h>  // Include file for standard input/output
#include <stdlib.h> // so we can use atoi()
#include <time.h>   // so we can use time_t and clock_gettime()

#include "fib.c"

// test single dynamic programming fib function
void testSingleNumber(int n){
    int ops = 0;
    printf("fib%d is %llu, operations taken: %d\n",
        n,fibdp(n,&ops),ops);
}
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

    // Sort our integer array
    testSingleNumber(data1);
    testSingleNumber(data2);
    testSingleNumber(data3);
    testSingleNumber(data4);
    testSingleNumber(data5);
    testSingleNumber(data6);


    // printIntArray(data1, 11);
    // printIntArray(data2, 11);
    // printIntArray(data3, 11);
    // printIntArray(data4, 11);
    // printIntArray(data5, 11);
    // printIntArray(data6, 11);

    return 0;
}