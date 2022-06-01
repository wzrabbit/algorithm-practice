n = int(input())
arr = list(map(int, input().split()))
arr.insert(0, 0)

q = int(input())
for _ in range(q):
    gender, change = map(int, input().split())

    if gender == 1:
        for i in range(change, n + 1, change):
            arr[i] = 1 - arr[i]
    else:
        l = change - 1
        r = change + 1
        arr[change] = 1 - arr[change]
        while l >= 1 and r <= n:
            if arr[l] == arr[r]:
                arr[l] = 1 - arr[l]
                arr[r] = 1 - arr[r]
                l -= 1
                r += 1
            else:
                break

for i in range(1, n + 1):
    print(arr[i], end=' ')
    if i % 20 == 0:
        print()
