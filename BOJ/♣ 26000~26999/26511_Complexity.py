N = int(input())

for _ in range(N):
    S = input()
    char_count = [0] * 26

    for cur in S:
        char_count[ord(cur) - ord('a')] += 1

    for i in range(26):
        if char_count[i] == 0:
            char_count[i] = 99999

    char_count.sort()
    complexity = len(set(list(S)))
    cost = 0

    for i in range(26):
        if complexity <= 2:
            break

        cost += char_count[i]
        complexity -= 1

    print(cost)
