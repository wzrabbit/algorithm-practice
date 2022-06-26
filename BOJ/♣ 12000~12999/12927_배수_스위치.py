bulb = list(input())
bulb.insert(0, '')
cnt = 0

for i in range(1, len(bulb)):
    if bulb[i] == 'Y':
        for j in range(i, len(bulb), i):
            bulb[j] = 'N' if bulb[j] == 'Y' else 'N'
        cnt += 1

print(cnt)