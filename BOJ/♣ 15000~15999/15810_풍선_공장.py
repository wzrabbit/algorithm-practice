import sys
input = sys.stdin.readline
staff, bloon = list(map(int, input().split()))
data = list(map(int, input().split()))
start, end = 1, bloon * min(data)

while start <= end:
    mid = (start + end) // 2
    sum_ = 0
    for i in range(staff):
        sum_ += mid // data[i]
    if sum_ >= bloon:
        end = mid - 1
    else:
        start = mid + 1

print(start)
