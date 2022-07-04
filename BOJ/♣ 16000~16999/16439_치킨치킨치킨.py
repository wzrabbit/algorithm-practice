people, chicken = map(int, input().split())
db = []

for i in range(people):
    db.append(list(map(int, input().split())))

best = 0
for i in range(chicken - 2):
    for j in range(i + 1, chicken - 1):
        for k in range(j + 1, chicken):
            current = 0
            for p in range(people):
                current += max(db[p][i], db[p][j], db[p][k])

            if current > best:
                best = current

print(best)
