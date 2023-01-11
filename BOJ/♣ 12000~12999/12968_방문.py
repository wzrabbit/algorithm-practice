R, C, K = map(int, input().split())

if K == 1 or R * C % 2 == 0:
    print(1)
else:
    print(0)
