import sys
import math
input = sys.stdin.readline

parts, dollar = list(map(int, input().split()))
data = []
for i in range(parts):
    data.append(list(map(int, input().split())))

start, end = 0, 100010
while start <= end:
    mid = (start + end) // 2
    left = dollar
    success = True
    
    for i in range(len(data)):
        cost, already, small, smallPrice, big, bigPrice = data[i]
        need = mid * cost - already
        min_ = 10 ** 7
        for s in range(need // small + 2):
            b = math.ceil((need - small * s) / big)
            if s * smallPrice + b * bigPrice < min_:
                min_ = s * smallPrice + max(0, b) * bigPrice
        left -= min_
        if left < 0:
            success = False
            break

    if success:
        start = mid + 1
    else:
        end = mid - 1

print(end)