import math

N, A, B, C, D = map(int, input().split())

print(min(
    math.ceil(N / A) * B,
    math.ceil(N / C) * D
))
