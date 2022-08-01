import sys
input = sys.stdin.readline

R, C = map(int, input().split())
_, __, PR, PC = map(int, input().split())
pillow_size = PR * PC
display_size = 0
board = []

for r in range(R):
    board.append(list(input().strip()))

for r in range(R):
    for c in range(C):
        if board[r][c] == 'P':
            display_size += 1

if display_size < pillow_size:
    print(1)
else:
    print(0)
