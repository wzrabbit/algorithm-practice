import sys
input = sys.stdin.readline
print_ = sys.stdout.write

caseA = int(input())
word = list(map(int, input().split(' ')))
dp = [['X' for c in range(caseA)] for r in range(caseA)]

for c in range(caseA):
    for r in range(c + 1):
        if r == c:
            dp[r][c] = 'O'
        elif word[r] != word[c]:
            dp[r][c] = 'X'
        elif dp[r + 1][c - 1] == 'O':
            dp[r][c] = 'O'
        elif abs(r - c) == 1:
            dp[r][c] = 'O'
        else:
            dp[r][c] = 'X'  

caseB = int(input())
for _ in range(caseB):
    s, e = list(map(int, input().split(' ')))
    if dp[s - 1][e - 1] == 'O':
        print_('1\n')
    else:
        print_('0\n')