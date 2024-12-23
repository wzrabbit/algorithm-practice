import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    
    if N == 1 or M == 1:
        print("YES\n")
        continue

    if (N + M - 4) % 2 == 1:
        print("YES\n")
    else:
        print("NO\n")
