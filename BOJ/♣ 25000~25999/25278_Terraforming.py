mars = {'ocean': 0, 'oxygen': 0, 'temperature': -30}

n = int(input())
for _ in range(n):
    condition, change = input().split(' ')
    change = int(change)
    mars[condition] += change

if mars['ocean'] >= 9 and mars['oxygen'] >= 14 and mars['temperature'] >= 8:
    print('liveable')
else:
    print('not liveable')
