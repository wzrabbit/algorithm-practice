N = int(input())
arr = list(map(int, input().split()))

if sum(arr) % 2 == 1:
    print(1)
    exit()

left = arr[0]

for i in range(1, N - 1):
    left += arr[i]
    if left % 2 == 0:
        print(1)
        exit()

print(0)
