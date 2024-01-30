while True:
    N = int(input())

    if N == 0:
        break

    arr = []

    for __ in range(N):
        cur = int(input())
        arr.append(cur)

    for i in reversed(range(N)):
        print(arr[i])

    print(0)
