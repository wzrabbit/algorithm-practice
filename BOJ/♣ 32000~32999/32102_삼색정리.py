import sys
print = sys.stdout.write

N, M = map(int, input().split())
R, G, B = map(int, input().split())
limit = (N * M + 1) // 2
goal = {
    'R': R,
    'G': G,
    'B': B,
}

if max(R, G, B) > limit:
    print('NO')
    exit()

print('YES\n')

grid = [['' for _ in range(M)] for _ in range(N)]
arr = sorted([[R, 'R'], [G, 'G'], [B, 'B']], reverse=True)
order = [arr[0][1], arr[1][1], arr[2][1]]

count = {
    'R': 0,
    'G': 0,
    'B': 0,
}

for r in range(N):
    for c in range(M):
        if (r + c) % 2 == 0:
            grid[r][c] = order[0]
            count[order[0]] += 1
        else:
            grid[r][c] = order[1]
            count[order[1]] += 1


if N >= M:
    cur = order[0]
    for r in range(N):
        for c in range(M):
            if (r + c) % 2 == 0 and count[cur] > goal[cur]:
                grid[r][c] = order[2]
                count[cur] -= 1

    cur = order[1]
    for r in reversed(range(N)):
        for c in reversed(range(M)):
            if (r + c) % 2 == 1 and count[cur] > goal[cur]:
                grid[r][c] = order[2]
                count[cur] -= 1
else:
    cur = order[0]
    for c in range(M):
        for r in range(N):
            if (r + c) % 2 == 0 and count[cur] > goal[cur]:
                grid[r][c] = order[2]
                count[cur] -= 1

    cur = order[1]
    for c in reversed(range(M)):
        for r in reversed(range(N)):
            if (r + c) % 2 == 1 and count[cur] > goal[cur]:
                grid[r][c] = order[2]
                count[cur] -= 1

for r in range(N):
    for c in range(M):
        print(f'{grid[r][c]}')
    print('\n')
