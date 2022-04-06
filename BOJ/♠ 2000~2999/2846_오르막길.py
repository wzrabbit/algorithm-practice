n = int(input())
road = list(map(int, input().split()))
max_ = 0
current = 0

for i in range(1, len(road)):
    if road[i] > road[i - 1]:
        current += road[i] - road[i - 1]
    else:
        max_ = max(max_, current)
        current = 0

max_ = max(max_, current)
print(max_)
