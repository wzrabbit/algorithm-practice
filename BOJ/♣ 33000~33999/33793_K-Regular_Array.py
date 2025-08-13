import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    N, K = map(int, input().split())

    for i in range(N):
        print(f'{K - (i % K)} ')
    
    print('\n')
