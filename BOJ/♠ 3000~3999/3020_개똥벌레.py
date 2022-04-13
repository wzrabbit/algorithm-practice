import sys
input = sys.stdin.readline

obstacle, lane = map(int, input().split())
top = [0] * (lane + 1)
bottom = [0] * (lane + 1)

for _ in range(obstacle // 2):
    top[int(input())] += 1
    bottom[lane + 1 - int(input())] += 1

for i in range(lane):
    top[i] += top[i - 1]

for i in reversed(range(lane)):
    bottom[i] += bottom[i + 1]
