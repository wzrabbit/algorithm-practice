n, w = map(int, input().split())
income = list(map(int, input().split()))
max_ = 0
sum_ = 0

for i in range(w):
    sum_ += income[i]
max_ = sum_

for i in range(n - w, n):
    sum_ = sum_ - income[i - w] + income[i]
    max_ = max(max_, sum_)

print(max_)
