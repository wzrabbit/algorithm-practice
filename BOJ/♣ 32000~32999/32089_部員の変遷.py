while True:
    N = int(input())

    if N == 0:
        break

    arr = list(map(int, input().split()))
    max_sum = 0

    for i in range(N - 2):
        max_sum = max(max_sum, sum(arr[i:i+3]))

    print(max_sum)
