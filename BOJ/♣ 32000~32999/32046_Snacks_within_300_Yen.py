while True:
    N = int(input())
    
    if N == 0:
        break

    arr = list(map(int, input().split()))
    cost = 0

    for i in range(N):
        if cost + arr[i] <= 300:
            cost += arr[i]

    print(cost)
