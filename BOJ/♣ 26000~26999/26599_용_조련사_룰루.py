import sys
input = sys.stdin.readline
print = sys.stdout.write

N, M = map(int, input().split())
dragons = list(map(int, input().split()))
success = True

for i in range(N):
    dragons[i] = (dragons[i], i + 1)

dragons.sort(reverse=True)

for i in range(min(3, N - 1)):
    if dragons[i][0] > dragons[i + 1][0] + M:
        success = False
        break

if success:
    print('YES\n')
    for i in range(N):
        if i == 2 or i == 3:
            continue
        print(f'{dragons[i][1]} ')
    for i in range(2, min(N, 4)):
        print(f'{dragons[i][1]} ')
else:
    print('NO')
