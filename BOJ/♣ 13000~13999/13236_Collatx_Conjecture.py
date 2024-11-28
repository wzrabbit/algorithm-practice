N = int(input())

while True:
    print(N, end=" ")

    if N == 1:
        break

    if N % 2 == 0:
        N //= 2
    else:
        N = 3 * N + 1
