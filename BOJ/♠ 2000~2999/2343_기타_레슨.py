import sys
input = sys.stdin.readline
video, blue = list(map(int, input().split()))
data = list(map(int, input().split()))
start, end = max(data), max(data) * len(data)

while start <= end:
    mid = (start + end) // 2
    left = blue
    capacity = mid
    fail = False
    for i in range(len(data)):
        if capacity - data[i] >= 0:
            capacity -= data[i]
        else:
            left -= 1
            if left == 0:
                fail = True
                break
            capacity = mid - data[i]
    if fail:
        start = mid + 1
    else:
        end = mid - 1

print(start)
