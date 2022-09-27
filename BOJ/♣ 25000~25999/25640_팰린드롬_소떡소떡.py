N = int(input())
arr = list(input().strip())
l = 0
r = N - 1
cnt = 0

while l < r:
    if arr[l] != arr[r]:
        cnt += 1
    l += 1
    r -= 1

print(cnt)
