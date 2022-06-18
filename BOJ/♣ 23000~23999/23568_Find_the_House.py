import sys
input = sys.stdin.readline

n = int(input())
db = dict()
direction = {'L': -1, 'R': 1}

for _ in range(n):
    a, b, c = input().strip().split()
    db[int(a)] = (b, int(c))

current = int(input())
for i in range(n):
    current = current + direction[db[current][0]] * db[current][1]

print(current)
