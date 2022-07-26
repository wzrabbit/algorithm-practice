row, col, color = map(int, input().split())
block = list(map(int, input().split()))
board = [[''] * col for _ in range(row)]
idx = 0

for i in range(color):
    for j in range(block[i]):
        if idx // col % 2 == 0:
            board[idx // col][idx % col] = str(i + 1)
        else:
            board[idx // col][col - 1 - idx % col] = str(i + 1)
        idx += 1

for r in range(row):
    print(''.join(board[r]))
