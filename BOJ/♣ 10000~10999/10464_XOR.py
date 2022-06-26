import sys
input = sys.stdin.readline
print = sys.stdout.write


def get_XOR(N):
    if N % 4 == 0:
        return N
    elif N % 4 == 1:
        return 1
    elif N % 4 == 2:
        return N + 1
    else:
        return 0


T = int(input())
for _ in range(T):
    A, B = map(int, input().split())
    print(f'{get_XOR(A - 1) ^ get_XOR(B)}\n')
