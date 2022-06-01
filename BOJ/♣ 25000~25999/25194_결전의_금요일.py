import sys
input = sys.stdin.readline
n = int(input())
arr = list(map(int, input().split()))
cnt = [0] * 7
dp = [[False] * 7 for i in range(n + 1)]
dp[0][0] = True

for i in range(len(arr)):
    cnt[arr[i] % 7] += 1

for r in range(0, n):
    for c in range(7):
        if dp[r][c] == True:
            dp[r + 1][c] = True
            dp[r + 1][(c + arr[r]) % 7] = True

if dp[n][4] == True:
    print('YES')
else:
    print('NO')
