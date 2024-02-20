plus, minus = map(int, input().split())

for i in range(minus, 1001):
    if i * 2 - minus == plus:
        print(i, i - minus)
        exit(0)

print(-1)
