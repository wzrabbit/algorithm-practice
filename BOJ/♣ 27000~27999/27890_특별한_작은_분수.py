x, N = map(int, input().split())

for _ in range(N):
    if x % 2 == 0:
        x = (x // 2) ^ 6
    else:
        x = (x * 2) ^ 6

print(x)
