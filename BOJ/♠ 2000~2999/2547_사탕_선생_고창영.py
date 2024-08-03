T = int(input())

for _ in range(T):
    input()

    N = int(input())
    total = 0

    for __ in range(N):
        cur = int(input())
        total += cur

    if total % N == 0:
        print('YES')
    else:
        print('NO')
