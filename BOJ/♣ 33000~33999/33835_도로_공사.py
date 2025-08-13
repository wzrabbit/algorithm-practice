import sys
import math
input = sys.stdin.readline

N = int(input())
x1, y1 = map(int, input().split())

for _ in range(N - 2):
    input()

x2, y2 = map(int, input().split())

print(math.sqrt(abs(x2 - x1) ** 2 + abs(y2 - y1) ** 2))
