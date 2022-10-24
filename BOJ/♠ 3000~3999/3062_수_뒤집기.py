T = int(input())
for _ in range(T):
    N = int(input())
    N += int(str(N)[::-1])

    N = str(N)
    if N == N[::-1]:
        print('YES')
    else:
        print('NO')
