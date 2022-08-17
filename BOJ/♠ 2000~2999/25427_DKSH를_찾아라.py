# 대회 당시의 코드라 가독성이 좀 별로입니다

import sys
input = sys.stdin.readline

N = int(input())
text = list(input().strip())

D = [0] * N
K = [0] * N
S = [0] * N
H = [0] * N

if text[0] == 'D':
    D[0] = 1

for i in range(1, N):
    D[i] = D[i - 1]
    if text[i] == 'D':
        D[i] += 1

for i in range(1, N):
    K[i] = K[i - 1]
    if text[i] == 'K':
        K[i] += D[i - 1]

for i in range(1, N):
    S[i] = S[i - 1]
    if text[i] == 'S':
        S[i] += K[i - 1]

for i in range(1, N):
    H[i] = H[i - 1]
    if text[i] == 'H':
        H[i] += S[i - 1]

print(H[N - 1])
