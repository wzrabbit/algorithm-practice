N = int(input())
exp = []

for _ in range(N):
    exp.append(list(map(int, input().split())))

exp.sort(key=lambda x: x[0])

total = 0
for i in range(N):
    total += exp[i][0] * (i + 1) + exp[i][1]

print(total)
