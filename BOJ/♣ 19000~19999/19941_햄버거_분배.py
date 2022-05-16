import sys
input = sys.stdin.readline

n, r = map(int, input().split())
arr = list(input().strip())
cnt = 0

for i in range(n):
    if arr[i] != 'P':
        continue
    for j in range(max(0, i - r), min(i + r + 1, n)):
        if arr[j] == 'H':
            arr[j] = 'O'
            cnt += 1
            break

print(cnt)
