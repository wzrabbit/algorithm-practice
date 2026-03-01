H, M = map(int, input().split())
N = int(input())
time = [False] * 1440

for _ in range(N):
    h, m, d = map(int, input().split())
    start = h * 60 + m

    while start < 1440:
        time[start] = True
        start += d

current_time = H * 60 + M

while True:
    if time[current_time]:
        print(f"{current_time // 60:02d}:{current_time % 60:02d}")
        break
    current_time = (current_time + 1) % 1440
