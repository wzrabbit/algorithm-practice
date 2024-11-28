A, B, K = map(int, input().split())

if B % A != 0:
    print(-1)
    exit()

answer = [A, B]

for i in range(A * 2, B, A):
    if B % i == 0:
        answer.append(i)

if len(answer) >= K:
    print(*answer[:K])
else:
    print(-1)
