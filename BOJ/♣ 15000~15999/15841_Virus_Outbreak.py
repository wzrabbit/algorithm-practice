dp = [0] * 491
dp[1] = 1
dp[2] = 1

for i in range(3, 491):
    dp[i] = dp[i - 1] + dp[i - 2]

while True:
    N = int(input())

    if N == -1:
        break

    print(f'Hour {N}: {dp[N]} cow(s) affected')
