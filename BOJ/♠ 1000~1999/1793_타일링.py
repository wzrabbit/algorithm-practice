dp = [0] * 251
dp[0] = 1
dp[1] = 1

for i in range(1, 251):
    dp[i] = dp[i - 1] + dp[i - 2] * 2

while True:
    try:
        N = int(input())
        print(dp[N])
    except EOFError:
        break
