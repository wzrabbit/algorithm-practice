N, K = map(int, input().split())
arr = list(map(int, input().split()))
limit = 0

for i in range(K):
    limit += arr[i] - arr[i] // 2
    
if N <= limit:
    print('YES')
else:
    print('NO')
