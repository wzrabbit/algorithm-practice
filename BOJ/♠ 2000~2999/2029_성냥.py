board = []
for _ in range(10):
    board.append(list(input()))
deleted = 0
square = 0

dr1 = (1, 0, 1, 3)
dc1 = (0, 1, 3, 1)
dr4 = (1, 4, 1, 4, 0, 0, 6, 6)
dc4 = (0, 0, 6, 6, 1, 4, 1, 4)
dr9 = (1, 4, 7, 1, 4, 7, 0, 0, 0, 9, 9, 9)
dc9 = (0, 0, 0, 9, 9, 9, 1, 4, 7, 1, 4, 7)

# 지워진 성냥의 개수
for r in (0, 3, 6, 9):
    for c in (1, 4, 7):
        if board[r][c] == '.':
            deleted += 1

for r in (1, 4, 7):
    for c in (0, 3, 6, 9):
        if board[r][c] == '.':
            deleted += 1

# 1-정사각형
for r in (0, 3, 6):
    for c in (0, 3, 6):
        success = True
        for i in range(4):
            if board[r + dr1[i]][c + dc1[i]] == '.':
                success = False
                break
        if success:
            square += 1

# 4-정사각형
for r in (0, 3):
    for c in (0, 3):
        success = True
        for i in range(8):
            if board[r + dr4[i]][c + dc4[i]] == '.':
                success = False
                break
        if success:
            square += 1

# 9-정사각형
success = True
for i in range(12):
    if board[dr9[i]][dc9[i]] == '.':
        success = False
        break
if success:
    square += 1


print(deleted, square)
