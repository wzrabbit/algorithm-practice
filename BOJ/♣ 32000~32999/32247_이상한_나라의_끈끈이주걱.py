import sys
input = sys.stdin.readline

N, M = map(int, input().split())
obstacles = []

for _ in range(M):
    c, x, h = map(int, input().split())
    obstacles.append((c, x, h))

obstacles.sort(key=lambda x: x[1])

cur_height = 0
prev_x = 0
success = True

for i in range(M):
    c, x, h = obstacles[i]

    if c == 0:
        cur_height = max(h + 1, cur_height - (x - prev_x))
    else:
        cur_height -= (x - prev_x)

        if cur_height >= h:
            success = False
            break

    prev_x = x

last_gap = N - prev_x
cur_height -= last_gap

if cur_height > 0:
    success = False

if success:
    print('stay')
else:
    print('adios')
