N, Q = map(int, input().split())
arr = list(map(int, input().split()))

for _ in range(Q):
    query = list(map(int, input().split()))

    if query[0] == 1:
        a, b = query[1:]
        a -= 1
        b -= 1
        print(sum(arr[a : b + 1]))
        arr[a], arr[b] = arr[b], arr[a]
    else:
        a, b, c, d = query[1:]
        a -= 1
        b -= 1
        c -= 1
        d -= 1
        print(sum(arr[a : b + 1]) - sum(arr[c : d + 1]))
