db = {
    '.': 0,
    'K': 0,
    'P': 1,
    'N': 3,
    'B': 3,
    'R': 5,
    'Q': 9,
    'k': 0,
    'p': -1,
    'n': -3,
    'b': -3,
    'r': -5,
    'q': -9,
}

score = 0

for _ in range(8):
    S = input()

    for cur in S:
        score += db[cur]

print(score)
