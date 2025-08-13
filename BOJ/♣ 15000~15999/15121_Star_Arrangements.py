N = int(input())

print(f'{N}:')

for i in range(1, 16400):
    for j in range(i, i + 2):
        if (N % (i + j) == j or N % (i + j) == 0) and i + j <= N and j - i <= 1 and i + j >= 3:
            print(f'{j},{i}')
