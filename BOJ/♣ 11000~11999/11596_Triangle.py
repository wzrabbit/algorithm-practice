A = sorted(list(map(int, input().split())))
B = sorted(list(map(int, input().split())))

if A == B and A[0] ** 2 + A[1] ** 2 == A[2] ** 2:
    print('YES')
else:
    print('NO')
