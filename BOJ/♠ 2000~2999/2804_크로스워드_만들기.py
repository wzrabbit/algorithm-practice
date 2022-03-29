str_A, str_B = input().split()
board = [['.' for c in range(len(str_A))] for r in range(len(str_B))]
success = False
for a in range(len(str_A)):
    for b in range(len(str_B)):
        if str_A[a] == str_B[b]:
            for x in range(len(str_A)):
                board[b][x] = str_A[x]
            for y in range(len(str_B)):
                board[y][a] = str_B[y]
            success = True
            break
    if success:
        break

for i in range(len(board)):
    print(''.join(board[i]))
