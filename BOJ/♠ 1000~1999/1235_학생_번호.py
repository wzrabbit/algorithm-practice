N = int(input())
words = []

for i in range(N):
    words.append(input())

L = len(words[0])

for i in range(1, L + 1):
    words_set = set()

    for j in range(N):
        words_set.add(words[j][L - i :])

    if len(words_set) == N:
        print(i)
        break
