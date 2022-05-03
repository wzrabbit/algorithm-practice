import sys
input = sys.stdin.readline

num, price = map(int, input().split())
dp = [0] * (price + 1)
dp[0] = 1
coin = []

for i in range(num):
    coin.append(int(input()))

for i in range(num):
    for j in range(coin[i], price + 1):
        dp[j] += dp[j - coin[i]]

print(dp[price])
