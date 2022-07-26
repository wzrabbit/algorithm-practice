R, C = map(int, input().split())
before = []
after = []
count = 0

for r in range(R):
    before.append(list(input()))

input()

for r in range(R):
    after.append(list(input()))

for r in range(R):
    for c in range(C):
        if before[r][c] == after[r][c]:
            count += 1

print(count)