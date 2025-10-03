A, B, C, D = map(int, input().split())
print(A + B + C + D - min(A, B, C, D) + 1)
