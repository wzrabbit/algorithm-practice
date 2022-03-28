num = int(input()) + 1
data = []
for i in range(num - 1):
    data.append(list(map(int, input().split())))
dp = [0] * num

if data[0][0] == 1:
    dp[0] = data[0][1]
else:
    dp[0] = 0

for i in range(1, num):
    dp[i] = dp[i - 1]
    for j in range(i - 1):
        if j + data[j][0] == i:
            dp[i] = max(dp[i], dp[j] + data[j][1])
    if i != num - 1 and data[i][0] == 1:
        dp[i] += data[i][1]

print(dp[num - 1])
