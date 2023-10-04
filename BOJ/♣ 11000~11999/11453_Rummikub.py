T = int(input())
color = {"b": 0, "g": 1, "r": 2, "y": 3}

for _ in range(T):
    N = int(input())
    card_checks = [[False for _ in range(101)] for _ in range(4)]
    cards = input().split()
    success = False

    for i in range(N):
        num = int(cards[i][:-1])
        char = cards[i][-1]
        card_checks[color[char]][num] = True

    for i in range(4):
        for j in range(1, 100):
            if False not in card_checks[i][j : j + 3]:
                success = True
                break

        if success:
            break

    for i in range(1, 101):
        score = 0

        for j in range(4):
            if card_checks[j][i]:
                score += 1

        if score >= 3:
            success = True
            break

    if success:
        print("YES")
    else:
        print("NO")
