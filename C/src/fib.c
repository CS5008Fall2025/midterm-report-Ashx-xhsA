#ifndef FIB_C
#define FIB_C


// Code frame from Lab Dynamic Programming
// this file includes 3 types of fib implements
// each implements has one function for generating single number
// and another function for generating fib array

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>


#define MAX 5000
#define PRINT_SINGLE 1
#define PRINT_ALL 2

typedef uint64_t ull;

// a memo to store data in dp
static ull table[MAX];

// initiate table
void table_init(){
    for(int i = 0; i< MAX; i++){
        table[i]= 0;
    }
}

// =============== fibdp ===============
// calculate and return the fib number of index n using dynamic programming.
// Params:
//       (1) 'n' is the index of the fib number to be generated
//       (2) 'ops' is a pointer to the operations taken counts
ull fibdp(int n, ull *ops)
{   
    // if n's fib is already in memo
    //return it directly
    if (table[n]){
        return table[n];
    }
    
    // base case
    if (n == 0 || n == 1){
        table[n] = n;
        return n;
    }
    
    // store data into memo
    table[n] = fibdp(n-1,ops) + fibdp(n-2,ops);
    (*ops)++;

    return table[n];
}

// =============== fibdp_full ===============
// using fibdp function to generate an array of fib number
// Params:
//       (1) 'n' is the index of the last fib number of the array
//       (2) 'ops' is a pointer to the operations taken counts
ull* fibdp_full(int n, ull *ops)
{   
    ull *row = malloc((sizeof(ull)) * (n+1));
    if(row == NULL){
        return NULL;
    }
    for (int i = 0; i <= n; i++)
    {
        row[i] = fibdp(i, ops);
    }
    // initiate table when function ends
    table_init();
    return row;
}

// =============== fibr ===============
// calculate and return the fib number of index n using recursion.
// Params:
//       (1) 'n' is the index of the fib number to be generated
//       (2) 'ops' is a pointer to the operations taken counts
ull fibr(int n, ull *ops)
{   
    ull fib_cur;
    
    // Base case
    if (n == 1 || n == 0)
    {
        fib_cur = n;
    }
    
    else
    {
        (*ops)++;
        // call recursion
        fib_cur = fibr(n - 1, ops) + fibr(n - 2, ops);
    }
    
    return fib_cur;
}

// =============== fibr_full ===============
// using fibr function to generate an array of fib number.
// Params:
//       (1) 'n' is the index of the last fib number of the array
//       (2) 'ops' is a pointer to the operations taken counts

ull* fibr_full(int n, ull *ops)
{
    ull *row = malloc((sizeof(ull)) * (n+1));
    if(row == NULL){
        return NULL;
    }
    for (int i = 0; i <= n; i++)
    {
        row[i] = fibr(i, ops);
    }
    return row;
}

// =============== fibi ===============
// calculate and return the fib number of index n using iteration.
// Params:
//       (1) 'n' is the index of the fib number to be generated
//       (2) 'ops' is a pointer to the operations taken counts
ull fibi(int n, ull *ops)
{   
    ull fib0 = 0;
    ull fib1 = 1;
    ull fib_cur;
    if (n==0) return fib0;
    if (n==1) return fib1;
    for (int i=2; i <= n; i++){
        (*ops)++;
        
        // update fib0, fib0 and fib_cur
        fib_cur = fib0 + fib1;
        fib0 = fib1;
        fib1 = fib_cur; 
    }
    return fib_cur;
}


// =============== fib_iterative ===============
// generate an array of fib numbers using iteration.
// Params:
//       (1) 'n' is the index of the fib number to be generated
//       (2) 'ops' is a pointer to the operations taken counts
ull *fib_iterative(int n, ull* ops){
    ull *row = malloc((sizeof(ull)) * (n+1));
    if (row == NULL){
        return NULL;
    }
    for (int i = 0; i <= n; i++)
    {   
        // store every value calculated in the row
        if (i == 0 || i ==1){
            row[i] =i;
        }
        else{
            (*ops)++;
            row[i] = row[i - 1] + row[i - 2];
        }
    }
    
    return row;
}

#endif
