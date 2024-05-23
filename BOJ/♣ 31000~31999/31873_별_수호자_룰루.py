import sys
input = sys.stdin.readline
print = sys.stdout.write

N, K = map(int, input().split())

if K == 1:
    print('NO')
    exit()
    
if K == N:
    if N * (N - 1) // 2 % K == 0:
        print('NO')
        exit()
        
    print('YES\n')
    
    for i in range(1, N + 1):
        print(f'{i} ')
    exit()

answer = []
cur = 1

for i in range(N // K):
    unit = []
    for j in range(K):
        unit.append(cur)
        cur += 1
    answer.append(unit)
    
if sum(answer[0]) % K == 0:
    for i in range(0, N // K - 1, 2):
        answer[i][0], answer[i + 1][1] = answer[i + 1][1], answer[i][0]
        
if K % 2 == 1:
    answer[0][0], answer[-1][2] = answer[-1][2], answer[0][0]

print('YES\n')

for i in range(N // K):
    for j in range(K):
        print(f'{answer[i][j]} ')
    print('\n')
