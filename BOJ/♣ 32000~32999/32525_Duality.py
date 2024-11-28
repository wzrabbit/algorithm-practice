import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    N = int(input())

    for i in range(1, N + 1):
        x, y = map(int, input().split())
        print(f'{i} {x + 1} {y + 500000000}\n')
