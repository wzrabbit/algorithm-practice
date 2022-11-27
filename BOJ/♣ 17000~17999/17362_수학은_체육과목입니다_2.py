N = int(input()) - 1
N %= 8

if N % 8 < 4:
    print(N + 1)
else:
    print(9 - N)
