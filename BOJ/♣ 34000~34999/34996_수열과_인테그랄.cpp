N = int(input())

print(N * (N + 1) - 1)

for i in range(1, N + 1):
    print(i, end=' ')

print(0, end=' ')

for i in range(-N, 0):
    print(i, end=' ')
