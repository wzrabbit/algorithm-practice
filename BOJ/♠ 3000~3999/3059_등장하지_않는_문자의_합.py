T = int(input())

for _ in range(T):
    text = input()
    score = 0
    is_used = [False] * 26

    for i in text:
        is_used[ord(i) - 65] = True

    for i in range(26):
        if not is_used[i]:
            score += i + 65

    print(score)
