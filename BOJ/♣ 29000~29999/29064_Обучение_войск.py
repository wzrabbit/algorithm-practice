N = int(input())
arr = list(map(int, input().split()))

print(max(0, N - N // 2 - arr.count(1)))
