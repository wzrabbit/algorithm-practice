import sys
input = sys.stdin.readline


def getDPValue(table, length):
    dp = [0] * length
    dp[0] = table[0]
    if length == 1:
        return dp[0]
    dp[1] = table[1]
    if length == 2:
        return max(dp[0], dp[1])
    dp[2] = table[0] + table[2]
    if length == 3:
        return max(dp[1], dp[2])
    for i in range(3, length):
        dp[i] = max(dp[i - 2] + table[i], dp[i - 3] + table[i])
    return max(dp[i - 1], dp[i])


while True:
    row, col = list(map(int, input().split(' ')))
    if row == 0 and col == 0:
        break
    line = []
    for _ in range(row):
        line.append(getDPValue(list(map(int, input().split(' '))), col))
    print(getDPValue(line, row))
