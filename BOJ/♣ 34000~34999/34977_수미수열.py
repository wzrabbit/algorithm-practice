N = int(input())
arr = list(map(int, input().split()))

for i in range(1, N // 2 + 1):
    if arr[:i] == arr[N - i:]:
        print('yes')
        exit()

print('no')
