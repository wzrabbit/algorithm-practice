import sys
input = sys.stdin.readline
num, need = list(map(int, input().split()))
tree = list(map(int, input().split()))
start, end = 0, max(tree)

while start <= end:
    mid = (start + end) // 2
    sum_ = 0
    for i in range(num):
        if tree[i] > mid:
            sum_ += tree[i] - mid
    if sum_ >= need:
        start = mid + 1
    else:
        end = mid - 1

print(end)