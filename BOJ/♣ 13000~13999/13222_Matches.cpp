N, W, H = map(int, input().split())

for _ in range(N):
    cur = int(input())

    if cur ** 2 <= W ** 2 + H ** 2:
        print("YES")
    else:
        print("NO")
