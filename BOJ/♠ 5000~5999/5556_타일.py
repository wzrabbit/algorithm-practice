N = int(input())
K = int(input())

for _ in range(K):
    x, y = map(int, input().split())
    dist = min(x - 1, y - 1, N - x, N - y)
    print(dist % 3 + 1)
    