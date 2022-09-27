N = int(input())
arr = list(map(int, input().split()))
odd = 0
even = 0

for i in range(N):
    if arr[i] % 2 == 0:
        even += 1
    else:
        odd += 1

if odd - 1 <= even <= odd:
    print(1)
else:
    print(0)
