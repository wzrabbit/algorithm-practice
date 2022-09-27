import sys
input = sys.stdin.readline
print = sys.stdout.write


def dfs(r, c, dir):
    global score
    state[r][c] = 'F'
    score += 1
    if r < 0 or r >= R or c < 0 or c >= C:
        return
    loop = grid[r][c] - 1

    for _ in range(loop):
        r += dr[dir]
        c += dc[dir]

        if 0 <= r < R and 0 <= c < C and state[r][c] == 'S':
            dfs(r, c, dir)


R, C, Q = map(int, input().split())
dr = {'N': -1, 'S': 1, 'W': 0, 'E': 0}
dc = {'N': 0, 'S': 0, 'W': -1, 'E': 1}
grid = []
state = [['S'] * C for _ in range(R)]
score = 0
for _ in range(R):
    grid.append(list(map(int, input().split())))

for i in range(Q):
    r, c, d = input().rstrip().split()
    r = int(r) - 1
    c = int(c) - 1
    dfs(r, c, d)

    r, c = map(int, input().split())
    state[r - 1][c - 1] = 'S'

print(f'{score}\n')
for r in range(R):
    for c in range(C):
        print(state[r][c] + ' ')
    print('\n')
