import math

A, B, C = map(int, input().split())
T = int(input())

if T <= 30:
    print(A)
    exit()

print(A + math.ceil((T - 30) / B) * C)
