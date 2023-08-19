N, K = map(int, input().split())
grid = []
best = -1_000_000_001

for _ in range(N):
    grid.append(list(map(int, input().split())))

for i in range(2**N):
    binary = bin(i)[2:].zfill(N)
    if binary.count("1") != K:
        continue

    cur = 0

    for j in range(N - 1):
        for k in range(j + 1, N):
            if binary[j] == binary[k] == "1":
                cur += grid[j][k]

    best = max(cur, best)

print(best)
