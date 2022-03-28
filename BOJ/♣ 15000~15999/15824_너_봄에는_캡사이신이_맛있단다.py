import sys
input = sys.stdin.readline

menu = int(input())
data = list(map(int, input().split()))
data.sort()
total = 0
mod = 1000000007
dp = [1 for i in range(menu + 1)]

for i in range(1, menu + 1):
    dp[i] = dp[i - 1] * 2 % mod

for i in range(menu):
    total += data[i] * (dp[i] - dp[menu - i - 1])
    total %= mod

print(total)
