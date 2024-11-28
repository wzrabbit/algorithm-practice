L, R, X = map(int, input().split())
db = set()

for i in range(L, R + 1):
    db.add(i | X)

for i in range(0, 5000):
    if i not in db:
        print(i)
        exit(0)
