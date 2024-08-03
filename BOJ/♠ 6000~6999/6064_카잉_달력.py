T = int(input())

for _ in range(T):
    N, M, X, Y = map(int, input().split())
    visited = [False] * (M + 1)
    answer = X
    x = X
    y = (X - 1) % M + 1
    success = True

    while True:
        if visited[y]:
            success = False
            break

        if y == Y:
            break

        visited[y] = True
        y = (y - 1 + N) % M + 1
        answer += N

    if success:
        print(answer)
    else:
        print(-1)
