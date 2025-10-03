dp = [2]

for i in range(1, 16):
    dp.append(sum(dp) + i + 1)

S = input()
print(dp.index(len(S)))
