dp = [0] * 1002
for i in range(2, 1002):
    if i % 2 == 0:
        dp[i] = dp[i - 1] * 2 + 1
    else:
        dp[i] = dp[i - 1] * 2 - 1

n = int(input())
print(dp[n])
