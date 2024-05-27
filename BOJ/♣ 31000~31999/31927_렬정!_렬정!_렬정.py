N = int(input())
arr = list(map(int, input().split()))

print(N // 2)

for i in range(N // 2):
    x = 1000000 - 6000 * (i + 1)
    arr[i] += x
    arr[N - i - 1] -= x
    print(*arr)

