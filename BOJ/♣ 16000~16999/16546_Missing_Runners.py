N = int(input())
runners = set(list(map(int, input().split())))

for i in range(1, N + 1):
    if i not in runners:
        print(i)
        break
