import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())
for _ in range(T):
    A, B = input().strip().split(' ')
    A = ''.join(sorted(list(A)))
    B = ''.join(sorted(list(B)))
    if A == B:
        print('Possible\n')
    else:
        print('Impossible\n')
