import sys
print = sys.stdout.write

N, B = map(int, input().split())
ban = [[False] * N for _ in range(N)]

if B > N * (N - 1) or N == 2 and B > 1:
    print('NO')
    exit(0)

for i in range(1, N - 1):
    ban[i][i] = True
ban[0][N - 1] = True
ban[N - 1][0] = True

print('YES\n')
for r in range(N):
    for c in range(N):
        if ban[r][c] or B == 0:
            print('.')
        else:
            print('#')
            B -= 1
    print('\n')
