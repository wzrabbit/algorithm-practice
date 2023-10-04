import sys

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
D = list(map(int, input().split()))
B = list(map(int, input().replace(".", "").split()))
P = 0

for i in range(N):
    if B[i] >= 10:
        P += A[i] * B[i] // 10 - D[i]
    else:
        P += A[i] - D[i] * B[i] // 10

print(P)
