A, B = map(int, input().split())

if abs(A - B) == 0:
    print(A * 2)
else:
    print(min(A, B) * 2 + 1)
