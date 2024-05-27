N = int(input())
possible_values = [2 ** 4, 2 ** 8, 2 ** 16, 2 ** 32]

if N not in possible_values:
    print(-1)
    exit()

X = possible_values.index(N) + 3

print(X, X)
print('1 ' * (X - 1))
print('1 ' * (X - 2) + str(X - 1))
