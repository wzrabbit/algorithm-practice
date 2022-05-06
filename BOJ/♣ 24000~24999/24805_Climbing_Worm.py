climb, fall, height = map(int, input().split())
worm = 0
day = 0

while worm < height:
    day += 1
    worm += climb
    if worm >= height:
        break
    worm -= fall

print(day)
