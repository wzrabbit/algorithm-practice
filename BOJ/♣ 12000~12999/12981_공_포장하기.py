ball = list(map(int, input().split()))
box = 0

for i in range(3):
    box += ball[i] // 3
    ball[i] %= 3

ball.sort()

if ball[1] != 0:
    box += max(ball)
elif ball[2] != 0:
    box += 1

print(box)
