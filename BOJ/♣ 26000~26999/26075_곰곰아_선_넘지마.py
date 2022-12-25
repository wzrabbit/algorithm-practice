import sys
input = sys.stdin.readline

A, B = map(int, input().split())
N = A + B
S = input().strip()
T = input().strip()
S_arr = []
T_arr = []
gap = 0

for i in range(N):
    if S[i] == '1':
        S_arr.append(i)

for i in range(N):
    if T[i] == '1':
        T_arr.append(i)

for i in range(len(S_arr)):
    gap += abs(S_arr[i] - T_arr[i])

X = gap // 2
Y = gap - X
print(X ** 2 + Y ** 2)
