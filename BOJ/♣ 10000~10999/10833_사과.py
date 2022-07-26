import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())
for _ in range(T):
    N = int(input())

    N %= 28
    if N == 0:
        N = 2
    elif 16 <= N <= 27:
        N = 30 - N

    binary = bin(N)[2:].zfill(4)

    for i in range(4):
        if binary[i] == '1':
            print('딸기')
        else:
            print('V')
    print('\n')
