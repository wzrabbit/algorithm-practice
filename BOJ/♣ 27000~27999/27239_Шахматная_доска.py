N = int(input())
print('abcdefgh'[(N - 1) % 8] + str((N - 1) // 8 + 1))
