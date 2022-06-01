import sys
input = sys.stdin.readline

n, l = map(int, input().split())
arr = list(map(int, input().split()))
sum_ = sum(arr[:l])
max_ = sum_

for i in range(l, n):
    sum_ = sum_ - arr[i - l] + arr[i]
    max_ = max(sum_, max_)

print(max_)
