import math

N = int(input())

for i in range(2, 100001):
    if i * i // 2 == N:
        print(i * 4)
        break
