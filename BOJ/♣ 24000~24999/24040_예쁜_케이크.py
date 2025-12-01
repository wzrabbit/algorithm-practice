import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    print('TAK' if N % 3 == 2 or N % 9 == 0 else 'NIE')
