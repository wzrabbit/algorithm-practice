import sys
input = sys.stdin.readline
print = sys.stdout.write
arr = [[0, 0]]

N, Q = map(int, input().split())
for i in range(1, N + 1):
    arr.append([i, N - i + 1])

idx = N + 1
for i in range(Q):
    x = int(input())
    arr[x][1] = idx
    idx += 1

arr.sort(key=lambda x: -x[1])

for i in range(N):
    print(f'{arr[i][0]}\n')
