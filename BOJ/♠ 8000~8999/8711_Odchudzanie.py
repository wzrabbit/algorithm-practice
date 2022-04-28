# 해당 문제는 메모리 제한이 데이터의 양에 비해 매우 빡빡하므로,
# 메모리가 덜 소모되는 map iterator를 이용하여 해결해야 합니다.

import sys
input = sys.stdin.readline
read = sys.stdin.read

data = iter(open(0).read().split())
n = int(next(data))

max_ = int(next(data))
ans = 0

for i in range(n):
    current = int(next(data))
    if current > max_:
        max_ = current
    if max_ - current > ans:
        ans = max_ - current

print(ans)
