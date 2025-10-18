[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/kdfTwECC)

# Midterm p1: Report on Analysis of Fibonacci Series

- **Author**: Zhanyi Chen
- **GitHub Repo**: [[linke to github repo with this report](https://github.com/CS5008Fall2025/midterm-report-Ashx-xhsA)]
- **Semester**:25 Spring
- **Languages Used**: c, python

## Overview

This report focuses on the speed differences between implementations of Fibonacci Series<sup>[1]</sup>

The **Fibonacci sequence** is a sequence in which each element is the sum of the two elements that precede it. Numbers that are part of the Fibonacci sequence are known as **Fibonacci numbers**, commonly denoted $F_n$ . Many writers begin the sequence with 0 and 1, although some authors start it from 1 and 1 and some (as did Fibonacci) from 1 and 2. Starting from 0 and 1, the sequence begins:

$$0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ... $$

The Fibonacci numbers may be defined by the recurrence relation<sup>[1]</sup> :

```math
 F_0 = 1, F_1 = 1\\ 

and\\

 F_n = F_{n - 1} + F_{n-2} \

( for \ n > 1)
```

There are multiple ways to implement **Fibonacci sequence** with code, each discussed in more detail below. However,
for the implementations I used in this report the following chart represents the Big O value.

| Version             | Big O    | Space Used |
| :------------------ | :------- | :--------- |
| Iterative           | $O(n)$   | $O(1)$     |
| Recursive           | $O(2^n)$ | $O(n)$     |
| Dynamic Programming | $O(n)$   | $O(n)$     |

- *Iterative*

  The iteratiive method has just one for loop, and maintains 3 variables. 

  ```
  Fib_i(n)
  		fib0 = 0
  		fib1 = 1
  		fib
  		for i=0, i< n, i++
  			fib = fib0 + fib1
  			fib0 = fib1
  			fib1 = fib
  ```

- *recursive*

  The  recurrence tree has n levels, the $i$th level has $2^i$ branches. So time complexity is $2^1 + 2^2 +2^3+...+2^n$, which is  $O(2^n)$. The depth is n so the space complexity is  $O(n)$.

  ```
                   F(n)
                    /\
              F(n-1)    F(n-2)
              /\             /\
       F(n-2)   F(n-3)  F(n-3) F(n-4)
       
         ..........
     F(n-(n-1))  F(n-n)
  ```

  

  ```
  Fib_r(n)
  		if n==0 or n==1 
  			return n
  		return Fib_r(n-1) + Fib_r(n-2)
  ```

  

- *dynamic programming*

  Dp methods stores every value in table, thus the space complexity is $O(n)$. It writes values into table n times thus it calculates n times, so the time complexity is $O(n)$.

  ```
  Fib_d(n)
  		table[0] = 1;
  		table[1] = 1;
  		if (table[n])
  			return table[n]
  		table[n] = table[n-1] + table[n-2]
  		return table[n]
  ```

From time complecity perspective, dynamic gramming is as efficient as iteration method. However iteration method has the smallest space complexity making it overall most efiicient method.

## Empirical Data & Discussion

I tested n from 0 to 40, the detail run time and operation results are in [runtime_c.csv](runtime_c.csv) and [operation_count.csv](operation_count.csv).

From the operation count in the table below we can see that the iterative method and dynamic programming have exactly the same number. That's because they all use some extra space(variables, memo table) to store the previous data, thus every index will only be calculated once, which saves a lot of redundant operaction.

Recursive method's operation count is exponential growth. it has many redundant steps.



#### Operations Count 

| **N** | **Iterative** | **Dynamic Programming** | **Recursive** |
| ----- | ------------: | ----------------------: | ------------: |
| 0     |             0 |                       0 |             0 |
| 1     |             0 |                       0 |             0 |
| 2     |             1 |                       1 |             1 |
| 3     |             2 |                       2 |             3 |
| 4     |             3 |                       3 |             7 |
| 5     |             4 |                       4 |            14 |
| 6     |             5 |                       5 |            26 |
| 7     |             6 |                       6 |            46 |
| 8     |             7 |                       7 |            79 |
| 9     |             8 |                       8 |           133 |
| 10    |             9 |                       9 |           221 |
| 11    |            10 |                      10 |           364 |
| 12    |            11 |                      11 |           596 |
| 13    |            12 |                      12 |           972 |
| 14    |            13 |                      13 |          1581 |
| 15    |            14 |                      14 |          2567 |
| 16    |            15 |                      15 |          4163 |
| 17    |            16 |                      16 |          6746 |
| 18    |            17 |                      17 |         10926 |
| 19    |            18 |                      18 |         17690 |
| 20    |            19 |                      19 |         28635 |
| 21    |            20 |                      20 |         46345 |
| 22    |            21 |                      21 |         75001 |
| 23    |            22 |                      22 |        121368 |
| 24    |            23 |                      23 |        196392 |
| 25    |            24 |                      24 |        317784 |
| 26    |            25 |                      25 |        514201 |
| 27    |            26 |                      26 |        832011 |

## Language Analysis

### Language 1: C

### Language 2:Python

### Comparison and Discussion Between Experiences

## Conclusions / Reflection

## References

1. Anon. 2025. Fibonacci sequence. (October 2025). Retrieved October 17, 2025 from https://en.wikipedia.org/wiki/Fibonacci_sequence 
