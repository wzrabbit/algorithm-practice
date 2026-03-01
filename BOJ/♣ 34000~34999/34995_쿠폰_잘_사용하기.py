import sys
input = sys.stdin.readline

N, S = input().split()
A = int(input())
N = int(N)
S = int(S.replace('?', '9'))

if A <= S:
    print(S)
else:
    print(-1)
