#!/bin/python3

import math
import os
import random
import re
import sys
from sys import setrecursionlimit

# Complete the unboundedKnapsack function below.
def search(sum_: int, arr: list, k: int, index: int):
    if sum_ > k:
        return max(0, sum_ - arr[index])
    if sum_ == k:
        return k

    searches = []

    for i, val in enumerate(arr):
        s = search(sum_ + val, arr, k, i)
        if s == k:
            return k
        searches.append(s)
    
    return max(searches)

def unboundedKnapsack(k, arr):
    limit = 1000000000
    setrecursionlimit(limit)

    return search(0, list(set(arr)), k, 0)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for i in range(t):
        nk = input().split()

        n = int(nk[0])

        k = int(nk[1])

        arr = list(map(int, input().rstrip().split()))

        result = unboundedKnapsack(k, arr)

        fptr.write(str(result) + '\n')

    fptr.close()

