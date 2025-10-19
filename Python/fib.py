"""
Code frame from sample_midterm
"""
from enum import Enum
from functools import lru_cache
import argparse
from typing import Callable
import sys
import time

STACK_LIMIT = 1000
sys.setrecursionlimit(100000)

OPS = 0


class fibType(Enum):
    ITERATIVE_DP_TOGETHER = 4
    ALL = 3
    DP = 2
    RECURSIVE = 1
    ITERATIVE = 0


@lru_cache(maxsize=None)
def fib_dp(n: int) -> int:
    """
    Solves the fib array using simple recursion and built
    in memoization
    Args:
        n: the nth fib number

    Returns:
        the addition of n-1, n-2
    """
    if n == 1 or n == 0:
        return n
    global OPS
    OPS += 1
    return fib_dp(n - 1) + fib_dp(n - 2)


def fib_r(n: int) -> int:
    """
    Solves the fib array using simple recursion
    Args:
        n (int): the nth number

    Returns:
        the addition of n-1, n-2,
    """
    if n == 1 or n == 0:
        return n
    global OPS
    OPS += 1
    return fib_r(n - 1) + fib_r(n - 2)


def recursive_fib(n: int, func=fib_r) -> list:
    """

    Args:
        func:
        n:
        print_it:

    Returns:

    """
    result = []
    #    if n > STACK_LIMIT:  # due to stack limit size, tabulate data first
    #        steps = n // STACK_LIMIT
    #        for step in range(1, steps):
    #            new_n = step * STACK_LIMIT
    #            for i in range(0, new_n + 1):
    #                func(new_n, i)
    n = n
    for i in range(0, n + 1):
        result.append(func(i))
    return result


def iterative_fib(n: int) -> list:
    """
    Generates the nth number in the fib array based on the
    method requested

    Args:
        n: the nth number to generate
        print_it:  print out all numbers as being generated
        version:  the type/method of generation

    Returns:
        the nth number of the fib array
    """
    global OPS
    arr = []
    for i in range(0, n + 1):
        if i == 1 or i == 0:
            arr.append(i)
        else:
            OPS += 1
            arr.append(arr[i - 1] + arr[i - 2])
    return arr[n]


def fib_dp_full(n: int) -> list:
    """
    Solves the fib array using simple recursion and built
    in memoization
    Args:
        n: the nth number

    Returns:
        the nth number of the fib array
    """
    return recursive_fib(n, func=fib_dp)


def fib_r_full(n: int) -> list:
    """
    Solves the fib triangle using simple recursion
    Args:
        n (int): the nth number

    Returns:
        the nth number of the fib triangle
    """
    return recursive_fib(n, func=fib_r)


def run_and_time(func: Callable, n: int, print_it: bool = False):
    """
    Runs the fib triangle generation, prints the number if requested
    and returns both the time and OPS used.

    Args:
        n (int): _description_
        algo (fibType): _description_
        print (bool): _description_
    """
    global OPS
    OPS = 0  # reset it
    start = time.perf_counter()
    result = func(n)
    end = time.perf_counter()
    if print_it:
        print(result)
    return end - start, OPS


def main(n: int, algo: fibType, print_it: bool):
    """
    Prints the string the Nth number/ generates the nth number of the fib triangle.

    Args:
        algo:
        print_type:
        n: the nth number to generate
    """
    if algo == fibType.RECURSIVE:
        print("Recursive Version")
        time, ops = run_and_time(fib_r_full, n, print_it)
        print(f"Time: {time}({ops})")
    elif algo == fibType.DP:
        print("Dynamic Programming Version")
        time, ops = run_and_time(fib_dp_full, n, print_it)
        print(f"Time: {time}({ops})")
    elif algo == fibType.ITERATIVE_DP_TOGETHER:
        time, ops = run_and_time(iterative_fib, n)
        time2, ops2 = run_and_time(fib_dp_full, n)
        print(f"{time:0.6f},{ops},{time2:0.6f},{ops2},-,-")
    elif algo == fibType.ALL:
        time, ops = run_and_time(iterative_fib, n)
        time2, ops2 = run_and_time(fib_dp_full, n)
        time3, ops3 = run_and_time(fib_r_full, n)
        print(f"{time:0.6f},{ops},{time2:0.6f},{ops2},{time3:0.6f},{ops3}")
    else:
        print("Iterative Version")
        time, ops = run_and_time(iterative_fib, n, print_it)
        print(f"Time: {time}({ops})")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="fib array")
    parser.add_argument("n", type=int, help="The nth number to generate")
    parser.add_argument(
        "--print", action="store_true", default=False, help="Print the nth number"
    )
    parser.add_argument(
        "algo",
        type=int,
        choices=[0, 1, 2, 3, 4],
        default=fibType.ITERATIVE.value,
        help="The type of algorithm to use: 0 = iterative, 1 = recursive, 2 = dp, 3 = all, 4 = iterative and dp together",
    )

    args = parser.parse_args()
    algo = fibType(args.algo)
    main(args.n, algo, args.print)
