import sys

input = sys.stdin.readline

N, M = map(int, input().split())
is_p = [-1] * (N + 1)
is_m = [-1] * (N + 1)

for _ in range(M):
    a, b, c = input().split()
    a = int(a)
    c = int(c)

    if b == "P":
        is_p[a] = c
    else:
        is_m[a] = c

minimum = 0
maximum = 0

for i in range(1, N + 1):
    if is_m[i] == 1:
        continue

    if is_p[i] == 0:
        continue

    if is_p[i] == 1:
        if is_m[i] == 0:
            minimum += 1

        maximum += 1

        continue

    if is_m[i] == 0:
        if is_p[i] == 1:
            minimum += 1

        maximum += 1

        continue

    maximum += 1

print(minimum, maximum)
