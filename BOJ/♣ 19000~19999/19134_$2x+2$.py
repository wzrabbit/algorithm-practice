N = int(input())
start = 1
gap = 2
total = 0

while start <= N:
    total += (N - start) // gap + 1
    if (N - start) >= gap // 2:
        total += 1

    start = 2 * start + 2
    start = 2 * start + 2
    gap *= 4

print(total)
