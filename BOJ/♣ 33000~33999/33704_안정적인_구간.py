N = int(input())
arr = list(map(int, input().split()))

if N == 2 and arr[0] > arr[1]:
    print("NO")
    exit()

print("YES")
