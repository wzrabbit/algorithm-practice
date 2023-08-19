N = int(input())
words = set()

for _ in range(N):
    word = input()
    is_duplicated = False

    for i in range(len(word)):
        new_word = word[i:] + word[:i]

        if new_word in words:
            is_duplicated = True
            break

    if not is_duplicated:
        words.add(word)

print(len(words))
