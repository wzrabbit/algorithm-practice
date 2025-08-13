import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    input()
    X = int(input())
    thorns = list(map(int, input().split()))
    minus = 0

    if thorns[0] >= 10:
        gap = thorns[0] - 9
        minus = gap
        thorns[0] = 9

    for i in range(1, X):
        thorns[i] -= minus
        gap = thorns[i] - thorns[i - 1]

        if gap >= 10:
            minus += gap - 9
            thorns[i] -= gap - 9
        
    N = max(thorns) + 10
    thorns = set(thorns)
    dp = [False] * N
    dp[0] = True

    for i in range(N - 1):
        if i < N - 4 and dp[i] and i + 4 not in thorns:
            dp[i + 4] = True

        if dp[i] and i + 1 not in thorns:
            dp[i + 1] = True
    
    print(f'{"POSSIBLE" if dp[-1] else "IMPOSSIBLE"}\n')
