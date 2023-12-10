import sys

input = sys.stdin.readline

N = int(input())
W, H = map(int, input().split())
arr = []
points = set()

for i in range(N):
    x, y = map(int, input().split())
    arr.append([x, y])
    points.add(f"{x},{y}")

answer = 0

for i in range(N):
    x, y = arr[i]
    other_points = [f"{x},{y + H}", f"{x + W},{y}", f"{x + W},{y + H}"]
    success = True

    for i in range(3):
        if other_points[i] not in points:
            success = False
            break

    if success:
        answer += 1

print(answer)
