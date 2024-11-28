import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    N = int(input())
    print(f'{N * (N + 1) // 2} {N ** 2} {N ** 2 + N}\n')
