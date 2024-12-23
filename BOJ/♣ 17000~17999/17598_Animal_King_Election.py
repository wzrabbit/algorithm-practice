lion_count = 0
tiger_count = 0

for _ in range(9):
    vote = input()

    if vote == 'Lion':
        lion_count += 1
    else:
        tiger_count += 1

if lion_count > tiger_count:
    print('Lion')
else:
    print('Tiger')
