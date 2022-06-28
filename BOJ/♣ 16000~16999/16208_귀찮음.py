N = int(input())
arr = list(map(int, input().split()))
sum_ = 0
part = 0

for i in range(N):
    sum_ += part * arr[i]
    part += arr[i]

print(sum_)
