N, P = map(int, input().split())
visited = [-1] * max(N + 1, P)
cur = N
visited[cur] = 0
turn = 1

while True:
    cur = cur * N % P
    if visited[cur] != -1:
        print(turn - visited[cur])
        exit()
    
    visited[cur] = turn
    turn += 1
