import math

A, B, C = map(int, input().split())

if A == 0:
    print(C ** 2 - B)
elif B == 0:
    print(C ** 2 - A)
else:
    print(int(math.sqrt(A + B)))
