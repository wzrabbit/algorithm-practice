import sys
input = sys.stdin.readline

R, C, K = map(int, input().split())
grid = [input().strip() for _ in range(R)]
S = input().strip()
N = len(S)
dp = [[[0 for _ in range(C)] for _ in range(R)] for _ in range(N)]
dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)

for r in range(R):
    for c in range(C):
        if grid[r][c] == S[0]:
            dp[0][r][c] = 1

for l in range(N - 1):
    for r in range(R):
        for c in range(C):
            for k in range(1, K + 1):
                for i in range(4):
                    next_r = r + dr[i] * k
                    next_c = c + dc[i] * k

                    if 0 <= next_r < R and 0 <= next_c < C and grid[next_r][next_c] == S[l + 1]:
                        dp[l + 1][next_r][next_c] += dp[l][r][c]

answer = 0

for r in range(R):
    for c in range(C):
        answer += dp[N - 1][r][c]

print(answer)
