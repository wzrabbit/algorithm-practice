num = int(input())
dp = [[0 for j in range(num)] for i in range(10)]
for i in range(10):
    dp[i][0] = 1

for i in range(1, num):
    for j in range(0, 10):
        for k in range(0, j + 1):
            dp[j][i] += dp[k][i - 1] % 10007

sum_ = 0
for i in range(10):
    sum_ += dp[i][num - 1]
print(sum_ % 10007)