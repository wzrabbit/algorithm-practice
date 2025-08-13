import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    L, R, S = map(int, input().split())
    
    if L == S or R == S:
        print(1)
        continue

    print(min((S - L) * 2 + 1, (R - S) * 2))
