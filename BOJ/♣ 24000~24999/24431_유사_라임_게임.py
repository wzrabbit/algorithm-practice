T = int(input())
for _ in range(T):
    N, L, F = map(int, input().split())
    words = input().split()
    db = dict()

    for i in range(N):
        suffix = words[i][(F * -1):]
        if suffix in db:
            db[suffix] += 1
        else:
            db[suffix] = 1

    counts = list(db.values())

    answer = 0
    for i in range(len(counts)):
        answer += counts[i] // 2

    print(answer)
