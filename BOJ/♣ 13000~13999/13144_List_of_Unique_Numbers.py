import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
num = [0] * 100001
kind = 1
length = 1
cnt = 0
l = 0
r = 0
num[arr[0]] = 1

while True:
    if kind == length:
        cnt += length
        r += 1
        if r == n:
            break
        num[arr[r]] += 1
        if num[arr[r]] == 1:
            kind += 1
        length += 1

    else:
        num[arr[l]] -= 1
        if num[arr[l]] == 0:
            kind -= 1
        length -= 1
        l += 1

print(cnt)
