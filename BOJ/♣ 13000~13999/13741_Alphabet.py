string = input()
n = len(string)
dp = [1] * n

for i in range(n):
    for j in range(i):
        if string[j] < string[i] and dp[j] + 1 > dp[i]:
            dp[i] = dp[j] + 1

print(26 - max(dp))
