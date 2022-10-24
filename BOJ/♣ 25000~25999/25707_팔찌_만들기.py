N = int(input())
marble = list(map(int, input().split()))
marble.sort()
ans = 0

for i in range(N - 1):
    ans += marble[i + 1] - marble[i]
ans += marble[-1] - marble[0]

print(ans)
