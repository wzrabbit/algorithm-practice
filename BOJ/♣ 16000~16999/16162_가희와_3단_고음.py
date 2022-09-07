import sys
input = sys.stdin.readline

N, A, D = map(int, input().split())
arr = list(map(int, input().split()))
need = A
cnt = 0

for i in range(N):
    if arr[i] == need:
        cnt += 1
        need += D

print(cnt)
