import sys
input = sys.stdin.readline
debug = print
print = sys.stdout.write

A = int(input())
B = int(input())
A_len = len(str(A))
B_len = len(str(B))
best = 0
skip = False

for i in range(A_len):
    if A % 10 == 0:
        skip = True
    for j in range(B_len):


print(f'{best}')
