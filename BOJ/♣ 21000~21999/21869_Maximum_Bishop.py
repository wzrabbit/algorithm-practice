import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input())

if N == 1:
    print('1\n')
else:
    print(f'{N * 2 - 2}\n')

for i in range(1, N + 1):
    print(f'1 {i}\n')

for i in range(2, N):
    print(f'{N} {i}\n')
