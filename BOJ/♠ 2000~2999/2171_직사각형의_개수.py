import sys
input = sys.stdin.readline

N = int(input())
dots = []
dots_set = set()

for _ in range(N):
    x, y = map(int, input().split())
    dots.append((x, y))
    dots_set.add((x, y))

rectangle_count = 0

for i in range(N - 1):
    for j in range(i + 1, N):
        ax, ay = dots[i]
        bx, by = dots[j]

        if ax == bx or ay == by:
            continue

        if (ax, by) in dots_set and (bx, ay) in dots_set:
            rectangle_count += 1

rectangle_count //= 2

print(rectangle_count)
