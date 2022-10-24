import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
for _ in range(N):
    S = input().strip()
    if S[len(S) // 2 - 1] == S[len(S) // 2]:
        print('Do-it\n')
    else:
        print('Do-it-Not\n')
