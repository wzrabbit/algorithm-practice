import sys
input = sys.stdin.readline

n, k = list(map(int, input().split()))
pie = list(map(int, input().split()))
sum_ = 0
max_ = 0

for i in range(k):
    pie.append(pie[i])

for i in range(k):
    sum_ += pie[i]
max_ = sum_

for i in range(k, k + n):
    sum_ = sum_ + pie[i] - pie[i - k]
    max_ = max(sum_, max_)

print(max_)
