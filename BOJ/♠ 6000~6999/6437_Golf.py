cnt = 1
text = ['Double eagle.', 'Eagle.', 'Birdie.',
        'Par.', 'Bogey.', 'Double Bogey.']

while True:
    goal, score = map(int, input().split())
    if goal == 0 and score == 0:
        break

    print('Hole #' + str(cnt))
    cnt += 1

    if score == 1:
        print('Hole-in-one.\n')
    else:
        idx = score - goal + 3
        if idx >= 6:
            idx = 5
        print(text[idx] + '\n')
