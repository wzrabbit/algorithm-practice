N = int(input())
A = []
B = []

for _ in range(N):
    A.append(list(map(int, input().split())))

for _ in range(N):
    B.append(list(map(int, input().split())))

one_count = 0

for i in range(N):
    for j in range(N):
        cur = 0
        
        for n in range(N):
            cur |= A[i][n] & B[n][j]

        if cur == 1:
            one_count += 1

print(one_count)
