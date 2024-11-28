A, B = map(int, input().split())

A = min(A, B + 1)
B = min(B, A - 1)

print(A + B)
