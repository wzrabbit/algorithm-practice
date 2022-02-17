import sys
input = sys.stdin.readline
num = int(input())
wine = []
for i in range(num):
    wine.append(int(input()))
dp = [[0 for j in range(num)] for i in range(3)]
dp[1][0] = wine[0]

for i in range(1, num):
    dp[0][i] = max(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1])
    dp[1][i] = dp[0][i - 1] + wine[i]
    dp[2][i] = dp[1][i - 1] + wine[i]

print(max(dp[0][num - 1], dp[1][num - 1], dp[2][num - 1]))