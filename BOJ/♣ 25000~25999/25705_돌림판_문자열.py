N = int(input())
roll = list(input())
K = int(input())
goal = list(input())
possible = True
cnt = 0

for i in range(K):
    if goal[i] not in roll:
        possible = False
        break

if possible:
    r = N - 1
    p = 0
    while p < K:
        r = (r + 1) % N
        cnt += 1
        if roll[r] == goal[p]:
            p += 1

if possible:
    print(cnt)
else:
    print(-1)
