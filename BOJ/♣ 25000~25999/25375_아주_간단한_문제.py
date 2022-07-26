import sys
input = sys.stdin.readline
print = sys.stdout.write

Q = int(input())
for _ in range(Q):
    a, b = map(int, input().split())
    if a != b and b % a == 0:
        print('1\n')
    else:
        print('0\n')
