T = int(input())

for _ in range(T):
    arr = sorted(list(map(int, input().split())))

    if arr[3] - arr[1] >= 4:
        print("KIN")
    else:
        print(sum(arr) - arr[0] - arr[4])
