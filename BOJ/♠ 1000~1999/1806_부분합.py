import sys
input = sys.stdin.readline

n, goal = map(int, input().split())
arr = list(map(int, input().split()))
sum_ = arr[0]
min_ = 100001
l = 0
r = 0
cnt = 0

while True:
    if sum_ >= goal:
        if r - l + 1 < min_:
            min_ = r - l + 1
        if arr[r] > goal:
            min_ = 1
            break
        else:
            sum_ -= arr[l]
            l += 1
    else:
        if r == n - 1:
            break
        r += 1
        sum_ += arr[r]

if min_ < 100001:
    print(min_)
else:
    print(0)
