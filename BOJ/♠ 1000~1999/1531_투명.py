q, l = map(int, input().split())
board = [[0] * 101 for _ in range(101)]

for _ in range(q):
    sc, sr, ec, er = map(int, input().split())
    for r in range(sr, er + 1):
        for c in range(sc, ec + 1):
            board[r][c] += 1

count = 0
for r in range(1, 101):
    for c in range(1, 101):
        if board[r][c] > l:
            count += 1

print(count)
