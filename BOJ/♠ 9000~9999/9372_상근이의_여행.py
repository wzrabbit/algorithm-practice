import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    V, E = map(int, input().split())
    print(V - 1)

    for __ in range(E):
        input()
