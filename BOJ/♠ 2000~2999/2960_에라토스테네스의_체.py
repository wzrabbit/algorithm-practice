n, k = map(int, input().split())
arr = [True] * (n + 1)
cnt = 1


def solve():
    global cnt

    for i in range(2, n + 1):
        if arr[i] == False:
            continue

        for j in range(i, n + 1, i):
            if arr[j] == True:
                arr[j] = False
                if cnt == k:
                    print(j)
                    return
                else:
                    cnt += 1


solve()
