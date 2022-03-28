import sys
from collections import deque

buy = int(sys.stdin.readline())
card = deque(map(int, sys.stdin.readline().split()))
card.appendleft(0)
dp = [0]

for i in range(1, buy + 1):
    min_ = 99999999999
    for j in range(1, len(card) + 1):
        if i < j or len(card) <= j:
            break
        elif dp[i - j] + card[j] < min_:
            min_ = dp[i - j] + card[j]
    dp.append(min_)

print(dp[buy])
