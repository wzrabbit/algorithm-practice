N = int(input())
prices = []
customers = []

for _ in range(N):
    require, cost = map(int, input().split())
    customers.append((require, cost))
    prices.append(require)

best_profit = 0
best_deal = 0
prices = sorted(list(set(prices)))

for i in range(len(prices)):
    cur_profit = 0

    for j in range(N):
        if customers[j][0] >= prices[i]:
            cur_profit += max(0, prices[i] - customers[j][1])

    print(prices[i], cur_profit)

    if cur_profit > best_profit:
        best_profit = cur_profit
        best_deal = prices[i]

print(best_deal)
