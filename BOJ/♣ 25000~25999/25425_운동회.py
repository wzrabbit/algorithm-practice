team, people, left, teamleft = map(int, input().split())

worst = min(team, left)
best = (left - teamleft) // people + 1
if (left - teamleft) % people != 0:
    best += 1

print(worst, best)
