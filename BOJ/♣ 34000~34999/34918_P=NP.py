import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    A, B = input().strip().split()

    if len(A) - A.rfind('P') == len(B) - B.rfind('P') and A.count('P') == B.count('P'):
        print('YES\n')
    else:
        print('NO\n')
