N = int(input())
rates = [int(input()) for _ in range(N)]
money = 10000

for i in range(N - 1):
    if rates[i] > rates[i + 1]:
        money = money * rates[i] // rates[i + 1]

print(str(money)[:-2] + '.' + str(money)[-2:])


