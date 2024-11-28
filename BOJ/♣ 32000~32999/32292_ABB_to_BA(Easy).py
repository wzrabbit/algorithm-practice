import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    N = int(input())
    S = input().strip()

    while 'ABB' in S:
        S = S.replace('ABB', 'BA')

    print(f'{S}\n')
