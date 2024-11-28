import sys
input = sys.stdin.readline
print = sys.stdout.write

N, M = map(int, input().split())
arr = list(map(int, list(input().strip())))

for i in range(N):
    if arr[i] == 0:
        continue
    
    if M >= 10 - arr[i]:
        M -= 10 - arr[i]
        arr[i] = 0

if M > 0:
    arr[-1] = (arr[-1] + M) % 10

for i in range(N):
    print(str(arr[i]))
