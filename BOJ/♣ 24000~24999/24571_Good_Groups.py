import sys
input = sys.stdin.readline

S = int(input())
S_arr = []
for _ in range(S):
    S_arr.append(input().strip().split())

D = int(input())
D_arr = []
for _ in range(D):
    D_arr.append(input().strip().split())

group = dict()
violated = 0
I = int(input())
for i in range(I):
    for name in input().strip().split():
        group[name] = i

for i in range(S):
    if group[S_arr[i][0]] != group[S_arr[i][1]]:
        violated += 1

for i in range(D):
    if group[D_arr[i][0]] == group[D_arr[i][1]]:
        violated += 1

print(violated)
