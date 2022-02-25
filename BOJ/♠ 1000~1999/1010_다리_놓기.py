import sys
input = sys.stdin.readline
print = sys.stdout.write

dp = [[0 for j in range(30)] for i in range(30)]
for i in range(30):
    dp[0][i] = i + 1
for i in range(1, 30):
    for j in range(i, 30):
        dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1]

test = int(input())
for i in range(test):
    left, right = list(map(int, input().split()))
    print(str(dp[left - 1][right - 1]) + '\n')
