X, K = map(int, input().split())
storage = [[] for _ in range(K + 1)]
storage[0] = [X]

for i in range(K):
    for j in range(len(storage[i])):
        cur = storage[i][j]
        storage[i + 1].append(cur // 2)
        storage[i + 1].append(cur - cur // 2)

total = 0

for i in range(K + 1):
    for j in range(len(storage[i])):
        total += storage[i][j]

print(total)
