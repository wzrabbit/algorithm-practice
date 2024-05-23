N = int(input())
prices = list(map(int, input().split()))
prices.sort()

answer = 1
start_price = prices[0]

for i in range(1, N):
    if prices[i] >= start_price * 2:
        start_price = prices[i]
        answer += 1

print(answer)
