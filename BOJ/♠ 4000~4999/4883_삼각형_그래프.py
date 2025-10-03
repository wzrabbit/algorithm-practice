import sys
input = sys.stdin.readline
print = sys.stdout.write

testcase_no = 1
INF = 400000000

while True:
    N = int(input())
    
    if N == 0:
        break

    grid = [list(map(int, input().split())) for _ in range(N)]
    dp = [[0] * 3 for _ in range(N)]
    dp[0] = [INF, grid[0][1], grid[0][1] + grid[0][2]]

    for i in range(1, N):
        for j in range(3):
            dp[i][j] = dp[i - 1][j] + grid[i][j]

            if j > 0:
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + grid[i][j], dp[i][j - 1] + grid[i][j])

            if j < 2:
                dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + grid[i][j])

    print(f'{testcase_no}. {dp[N - 1][1]}\n')
    testcase_no += 1
