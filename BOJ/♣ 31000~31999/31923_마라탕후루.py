N, P, Q = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
answer = [0] * N
success = True

for i in range(N):
    for _ in range(10000):
        if A[i] != B[i]:
            A[i] += P
            B[i] += Q
            answer[i] += 1
        else:
            break
    
    if A[i] != B[i]:
        success = False
        break

if success:
    print('YES')
    print(*answer)
else:
    print('NO')