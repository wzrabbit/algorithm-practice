import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())

    if N % 2 == 1:
        print(1)
    else:
        print(0)
