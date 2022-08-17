import math

A, B, C, D = map(int, input().split())
X = A // (C + 1) + (1 if A % (C + 1) > 0 else 0)
Y = B // (D + 1) + (1 if B % (D + 1) > 0 else 0)

print(X * Y)
