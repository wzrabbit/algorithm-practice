import sys
input = sys.stdin.readline
num, need = list(map(int, input().split()))
line = []
for i in range(num):
    line.append(int(input()))
start, end = 1, max(line)

while start <= end:
    mid = (start + end) // 2
    sum_ = 0
    for i in range(num):
        sum_ += line[i] // mid
    if sum_ >= need:
        start = mid + 1
    else:
        end = mid - 1

print(end)
