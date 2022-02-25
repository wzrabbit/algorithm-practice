import sys
from collections import deque
input = sys.stdin.readline
num, move = list(map(int, input().split()))
point = [[0, 0]]
for i in range(num):
    point.append(list(map(int, input().split())))
point.append([10000, 10000])


def canArrive(limit):
    visited = [False] * (num + 2)
    visited[0] = True
    queue = deque([[0, 0]])
    while len(queue):
        p, d = queue.popleft()
        if p == num + 1:
            return True
        if d <= move:
            for i in range(num + 2):
                if visited[i] == False:
                    x1, y1 = point[p]
                    x2, y2 = point[i]
                    if abs(x2 - x1) ** 2 + abs(y2 - y1) ** 2 <= limit ** 2:
                        visited[i] = True
                        queue.append([i, d + 1])
    return False


start, end = 1, 1415
while start <= end:
    mid = (start + end) // 2
    if canArrive(mid * 10):
        end = mid - 1
    else:
        start = mid + 1
print(start)
