def dfs(cur_r, cur_c, cnt):
    global max_
    alph = board[cur_r][cur_c]
    visited[alph] = True

    for i in range(4):
        r = cur_r + dr[i]
        c = cur_c + dc[i]
        if 0 <= r < R and 0 <= c < C and not visited[board[r][c]]:
            dfs(r, c, cnt + 1)

    if cnt > max_:
        max_ = cnt

    visited[alph] = False


R, C = map(int, input().split())
dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)
max_ = 0
board = []
visited = [False] * 27
for _ in range(R):
    cur = list(input())
    for i in range(C):
        cur[i] = ord(cur[i]) - 64
    board.append(cur)

dfs(0, 0, 1)
print(max_)
