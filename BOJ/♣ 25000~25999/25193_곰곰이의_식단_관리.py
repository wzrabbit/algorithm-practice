import sys
input = sys.stdin.readline

n = int(input())
schedule = list(input().strip())
other = 0

for i in range(n):
    if schedule[i] != 'C':
        other += 1

chicken = n - other
naive = [0] * (other + 1)

while chicken > 0:
    for i in range(len(naive)):
        naive[i] += 1
        chicken -= 1
        if chicken <= 0:
            break

print(max(naive))
