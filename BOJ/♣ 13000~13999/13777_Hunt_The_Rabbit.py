while True:
    N = int(input())

    if N == 0:
        break

    start = 1
    end = 50

    while True:
        mid = (start + end) // 2
        print(mid, end=' ')

        if N == mid:
            break

        if N > mid:
            start = mid + 1
        else:
            end = mid - 1

    print()
