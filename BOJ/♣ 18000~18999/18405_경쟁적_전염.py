from collections import deque
import sys
input = sys.stdin.readline

N = int(input().split()[0])
grid = []
first = []
visited = [[-1] * N for _ in range(N)]
dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)
success = False
q = deque()

for _ in range(N):
    grid.append(list(map(int, input().split())))

end_T, end_R, end_C = map(int, input().split())
end_R -= 1
end_C -= 1

for r in range(N):
    for c in range(N):
        if grid[r][c] != 0:
            first.append((r, c, grid[r][c]))
            visited[r][c] = 0

first.sort(key=lambda x: x[2])

for i in range(len(first)):
    q.append(first[i])

while len(q):
    cur_r, cur_c, cur_v = q.popleft()
    if cur_r == end_R and cur_c == end_C:
        success = True
        print(cur_v)
        break

    if visited[cur_r][cur_c] == end_T:
        continue

    for i in range(4):
        r = cur_r + dr[i]
        c = cur_c + dc[i]
        if 0 <= r < N and 0 <= c < N and visited[r][c] == -1:
            visited[r][c] = visited[cur_r][cur_c] + 1
            grid[r][c] = cur_v
            q.append((r, c, cur_v))

if not success:
    print(0)
