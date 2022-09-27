N = int(input())

for i in range(1, 101):
    if 1 + i + i ** 2 == N:
        print(i)
        break
