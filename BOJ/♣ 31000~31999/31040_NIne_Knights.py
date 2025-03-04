T = int(input())
dr = (-2, -2, -1, -1, 1, 1, 2, 2)
dc = (-1, 1, -2, 2, -2, 2, -1, 1)

for t in range(T):
    board = []

    for _ in range(5):
        board.append(input())

    if t != T - 1:
        input()

    is_valid = True
    
    for r in range(5):
        for c in range(5):
            if board[r][c] == ".":
                continue

            for i in range(8):
                nr = r + dr[i]
                nc = c + dc[i]

                if nr < 0 or nr >= 5 or nc < 0 or nc >= 5:
                    continue

                if board[nr][nc] == "k":
                    is_valid = False
                    break

    print("valid" if is_valid else "invalid")
