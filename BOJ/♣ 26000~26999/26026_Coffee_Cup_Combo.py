import sys
input = sys.stdin.readline

N = int(input())
stage = list(input())
cnt = 0
energy = 0

for i in range(N):
    if stage[i] == '1':
        energy = 3
    if energy > 0:
        energy -= 1
        cnt += 1
        
print(cnt)