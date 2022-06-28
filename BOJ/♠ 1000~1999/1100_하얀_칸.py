board = []
cnt = 0

for _ in range(8):
    board.append(list(input()))

for r in range(8):
    for c in range(8):
        if board[r][c] == 'F':
            if r % 2 == 0 and c % 2 == 0:
                cnt += 1
            elif r % 2 == 1 and c % 2 == 1:
                cnt += 1

print(cnt)
