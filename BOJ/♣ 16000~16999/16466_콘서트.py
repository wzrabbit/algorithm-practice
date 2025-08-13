import sys
input = sys.stdin.readline

N = int(input())
no_set = set(list(map(int, input().split())))

for i in range(1, N + 2):
    if i not in no_set:
        print(i)
        break
