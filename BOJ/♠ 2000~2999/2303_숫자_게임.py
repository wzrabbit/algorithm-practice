N = int(input())
winner = {'no': 0, 'score': 0}

for t in range(1, N + 1):
    card = list(map(int, input().split()))
    cur = 0

    for i in range(3):
        for j in range(i + 1, 4):
            for k in range(j + 1, 5):
                cur = max(cur, (card[i] + card[j] + card[k]) % 10)

    if cur >= winner['score']:
        winner['no'] = t
        winner['score'] = cur

print(winner['no'])
