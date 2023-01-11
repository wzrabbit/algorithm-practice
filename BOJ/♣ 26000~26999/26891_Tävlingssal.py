N = int(input())
SQRT = 31624
best = 10 ** 10

for x in range(1, SQRT):
    y = N // x
    if N % x != 0:
        y += 1

    best = min(best, (x + 1) * (y + 1))

print(best)
