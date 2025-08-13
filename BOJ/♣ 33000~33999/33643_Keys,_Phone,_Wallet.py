N = int(input())
items = [input() for _ in range(N)]
forgotten_items = []

for item in ('keys', 'phone', 'wallet'):
    if item not in items:
        forgotten_items.append(item)

if forgotten_items:
    print(*forgotten_items, sep='\n')
else:
    print('ready')
