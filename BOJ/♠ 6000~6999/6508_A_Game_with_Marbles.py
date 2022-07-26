while True:
    N = int(input())
    if N == 0:
        break

    arr = list(map(int, input().split()))
    ans = 0

    for i in range(N):
        ans += arr[i] * 2 ** i

    print(ans)
