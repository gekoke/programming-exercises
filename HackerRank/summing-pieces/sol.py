#!/bin/python3

import os
import sys

# Complete the summingPieces function below.
def summingPieces(arr):
    MOD = 10**9 + 7

    n = len(arr)
    
    if n == 1:
        return arr[0]

    counts = [-1 for _ in range((n // 2) + (n % 2))]
    counts[0] = (pow(2, n, MOD) - 1) % MOD
    prev = counts[0]
    y = n - 2

    for i in range(1, len(counts)):
        counts[i] = (prev + pow(2, y, MOD) - pow(2, i - 1, MOD)) % MOD
        y -= 1
        y %= MOD
        prev = counts[i]
    
    if (n % 2 == 0):
        counts += reversed(counts)
    else:
        counts += reversed(counts[:-1])
    
    return (sum([(arr[i] * counts[i]) % MOD for i in range(n)])) % (10**9 + 7)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = summingPieces(arr)

    fptr.write(str(result) + '\n')

    fptr.close()

