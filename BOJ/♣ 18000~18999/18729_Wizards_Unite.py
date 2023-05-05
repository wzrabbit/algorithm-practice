import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    N, K = map(int, input().split())
    chests = sorted(list(map(int, input().split())))

    best_time = max(sum(chests[:N - K]), chests[-1])
    print(f'{best_time}\n')
