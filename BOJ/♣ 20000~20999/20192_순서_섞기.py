import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
mode = 1
changed = 0
answer = 0

for i in range(1, n):
    if mode == 0:
        if arr[i - 1] < arr[i]:
            changed += 1
            mode = 1
    else:
        if arr[i - 1] > arr[i]:
            changed += 1
            mode = 0

while changed > 0:
    changed //= 2
    answer += 1

print(answer)
