import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
color = [0] * (n + 1)
current = 1
color[1] = 1

for i in range(2, n + 1):
    if color[i] != 0:
        continue

    current += 1
    for j in range(i, n + 1, i):
        if color[j] == 0:
            color[j] = current

print(str(current) + '\n')
for i in range(1, n + 1):
    print(str(color[i]) + ' ')
