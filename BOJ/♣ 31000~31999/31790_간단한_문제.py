N, P = map(int, input().split())
arr = list(map(int, input().split()))

if arr[0] != 1:
    print('NO')
    exit(0)

for i in range(1, N):
    if arr[i] != arr[i - 1] and arr[i] != arr[i - 1] + 1:
        print('NO')
        exit(0)
        
skips = P - 1
same_count = 1

for i in range(1, N):
    if arr[i] > arr[i - 1]:
        skips += P - 1
        same_count += 1
    else:
        skips -= 1
        
    if skips < 0:
        print('NO')
        exit(0)
        
limit_count = N // P

if N % P != 0:
    limit_count += 1
        
if same_count > limit_count:
    print('NO')
    exit(0)
        
print('YES')
