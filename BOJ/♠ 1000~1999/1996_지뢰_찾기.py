import sys
input = sys.stdin.readline
print = sys.stdout.write

dr = [-1, 1, 0, 0, -1, 1, -1, 1]
dc = [0, 0, -1, 1, -1, -1, 1, 1]

n = int(input())
land = []
result = [[0 for c in range(n)] for r in range(n)]

for _ in range(n):
    land.append(list(input().strip()))

for r in range(n):
    for c in range(n):
        if land[r][c] != '.':
            land[r][c] = int(land[r][c])

for r in range(n):
    for c in range(n):
        if land[r][c] != '.':
            result[r][c] = '*'
        else:
            for i in range(8):
                r_ = r + dr[i]
                c_ = c + dc[i]

                if 0 <= r_ < n and 0 <= c_ < n and land[r_][c_] != '.':
                    result[r][c] += land[r_][c_]

for r in range(n):
    for c in range(n):
        if result[r][c] != '*' and result[r][c] >= 10:
            result[r][c] = 'M'
        print(str(result[r][c]))
    print('\n')
