import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    A, B = map(int, input().split())

    while A != B:
        if A > B:
            A //= 2
        else:
            B //= 2

    print(A * 10)
