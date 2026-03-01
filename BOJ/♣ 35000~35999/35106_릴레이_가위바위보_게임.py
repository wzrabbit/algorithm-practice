N = int(input())
arr = list(map(int, input().split()))

for i in range(1, 4):
    if arr.count(i) == N - 1:
        print(i)
        break

for i in range(1, 4):
    if arr.count(i) == N + 1:
        print(i)
        break
