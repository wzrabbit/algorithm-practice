bus, minsik = map(int, input().split())
ans = 2 ** 32

for _ in range(bus):
    start, interval, cnt = map(int, input().split())
    current = start
    for i in range(cnt):
        if current >= minsik:
            ans = min(ans, current - minsik)
            break
        current += interval

if ans == 2 ** 32:
    print(-1)
else:
    print(ans)
