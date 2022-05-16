a, b = map(int, input().split())
cnt = 0

while a > b:
    if a % 2 == 0:
        a //= 2
    else:
        a += 1
    cnt += 1

cnt += b - a
print(cnt)
