N, M = map(int, input().split())
teammates = [list(map(int, input().split())) for _ in range(N)]
answer = 0
skip = False

for _ in range(M):
    x, y = map(int, input().split())
    success = True
    kicked = False

    if skip:
        skip = False
        continue

    for i in range(N):
        X, Y, R, S = teammates[i]
        can_kick = (X - x) ** 2 + (Y - y) ** 2 <= R ** 2

        if can_kick:
            kicked = True
        
        if i == 0 and not can_kick:
            success = False

        if can_kick and S > teammates[0][3]:
            success = False
            break

    if success:
        answer += 1

    if not kicked:
        skip = True

print(answer)
