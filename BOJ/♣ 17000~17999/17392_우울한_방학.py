import sys
input = sys.stdin.readline

n, day = map(int, input().split())
meet = list(map(int, input().split()))

piece = len(meet) + 1
gloomy = [0] * piece
left = day - sum(meet) - len(meet)
total = 0

while left > 0:
    for i in range(piece):
        if left > 0:
            gloomy[i] += 1
            total += gloomy[i] ** 2
            left -= 1
        else:
            break

print(total)
