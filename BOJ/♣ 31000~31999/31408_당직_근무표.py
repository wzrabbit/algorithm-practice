N = int(input())
cnt = [0] * 100_001
arr = list(map(int, input().split()))

for i in range(N):
    cnt[arr[i]] += 1

if max(cnt) <= N - N // 2:
    print("YES")
else:
    print("NO")
