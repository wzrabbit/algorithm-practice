X = int(input())

for i in range(X + 1, 10000):
    if (i // 100 + i % 100) ** 2 == i:
        print(i)
        exit()

print(-1)
