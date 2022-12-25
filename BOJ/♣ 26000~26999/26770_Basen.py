import sys
input = sys.stdin.readline

N = int(input())
times = list(map(int, input().split()))
is_going_right = True
prev = 0
count = 1

for i in range(N):
    if prev < times[i] and not is_going_right:
        is_going_right = True
        count += 1
    elif prev > times[i] and is_going_right:
        is_going_right = False
        count += 1
    prev = times[i]

print(count)
