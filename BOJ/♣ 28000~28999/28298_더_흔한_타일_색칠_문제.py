import sys

input = sys.stdin.readline
debug = print
print = sys.stdout.write

R, C, K = map(int, input().split())
grid = []
result = [[""] * C for _ in range(R)]
paint = 0

for r in range(R):
    grid.append(list(input().strip()))

for sr in range(0, K):
    for sc in range(0, K):
        frequencies = [0] * 26
        for r in range(sr, R, K):
            for c in range(sc, C, K):
                letter = grid[r][c]
                frequencies[ord(letter) - 65] += 1

        best = ""
        frequency = -1
        for i in range(26):
            if frequencies[i] > frequency:
                best = chr(i + 65)
                frequency = frequencies[i]

        for r in range(sr, R, K):
            for c in range(sc, C, K):
                if grid[r][c] != best:
                    paint += 1

                grid[r][c] = best

print(f"{paint}\n")
for r in range(R):
    for c in range(C):
        print(grid[r][c])
    print("\n")
