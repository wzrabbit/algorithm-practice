import sys
print = sys.stdout.write

N, K = map(int, input().split())

if K > N // 2:
    print('NIE')
    exit()

if N % 2 == 0:
    for i in range(1, N // 2 + 1):
        print(f'{i + N - N // 2} {i} ')
    exit()


for i in range(1, N // 2 + 1):
    print(f'{i} {i + N - N // 2} ')

print(f'{N // 2 + 1}')
