import sys

input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
dots = []

for i in range(N):
    dots.append(list(map(int, input().split())) + [i + 1])

dots.sort()

for i in range(N - 1):
    print(f"{dots[i][2]} {dots[i + 1][2]}\n")
