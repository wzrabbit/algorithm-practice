A, B, C, D = map(int, input().split())

if A * C % (B * D * 2) == 0:
    print(1)
else:
    print(0)
