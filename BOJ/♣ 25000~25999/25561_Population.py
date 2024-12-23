T = int(input())

for _ in range(T):
    start, time = map(int, input().split())
    print(start + time // 4 - time // 7)
