N = int(input())
arr = list(map(int, input().split()))
arr.sort(reverse=True)

if max(arr) == 0:
    print(0)
else:
    for i in range(N):
        if arr[i] >= i + 1 and (i == N - 1 or arr[i + 1] <= i + 1):
            print(i + 1)
            break
