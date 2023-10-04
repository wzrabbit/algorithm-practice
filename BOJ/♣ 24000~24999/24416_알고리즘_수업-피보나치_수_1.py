dp = [0, 1]
N = int(input())

for i in range(N - 1):
    dp.append(dp[-2] + dp[-1])

print(dp[-1], N - 2)
