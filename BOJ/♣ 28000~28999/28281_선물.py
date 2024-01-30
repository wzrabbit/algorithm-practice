N, X = map(int, input().split())
prices = list(map(int, input().split()))

best = 10**18

for i in range(N - 1):
    best = min(best, (prices[i] + prices[i + 1]) * X)

print(best)
