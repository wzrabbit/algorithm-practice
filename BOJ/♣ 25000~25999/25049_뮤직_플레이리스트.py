n = int(input())
arr = list(map(int, input().split()))
left_dp = [0] * n
right_dp = [0] * n

sum_ = 0
max_ = 0
for i in range(n):
    sum_ += arr[i]
    if sum_ < 0:
        sum_ = 0
    if sum_ > max_:
        max_ = sum_
    left_dp[i] = max_

sum_ = 0
max_ = 0
for i in reversed(range(n)):
    sum_ += arr[i]
    if sum_ < 0:
        sum_ = 0
    if sum_ > max_:
        max_ = sum_
    right_dp[i] = max_

max_ = 0
for i in range(n - 1):
    if left_dp[i] + right_dp[i + 1] > max_:
        max_ = left_dp[i] + right_dp[i + 1]

print(max_ + sum(arr))
