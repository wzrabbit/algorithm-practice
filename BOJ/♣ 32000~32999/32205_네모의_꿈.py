import sys
input = sys.stdin.readline

occupied = [False] * 1000001

N = int(input())

for _ in range(N):
    a, b, c = map(int, input().split())

    if occupied[a] or occupied[b] or occupied[c]:
        print(1)
        exit()

    occupied[a] = occupied[b] = occupied[c] = True

print(0)
