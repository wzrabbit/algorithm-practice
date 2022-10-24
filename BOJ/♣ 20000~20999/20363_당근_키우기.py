A, B = map(int, input().split())
if A < B:
    A, B = B, A
print(A + B + B // 10)
