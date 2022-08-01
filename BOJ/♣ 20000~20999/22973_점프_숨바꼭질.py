N = int(input())

if N % 2 == 1:
    count = 0
    N = abs(N)
    while N > 0:
        N //= 2
        count += 1

    print(count)
elif N == 0:
    print(0)
else:
    print(-1)
