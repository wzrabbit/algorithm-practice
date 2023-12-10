word = input()
generated_words = []

for i in range(len(word) - 2):
    for j in range(i + 1, len(word) - 1):
        cur_word = word[: i + 1][::-1] + word[i + 1 : j + 1][::-1] + word[j + 1 :][::-1]
        generated_words.append(cur_word)

generated_words.sort()

print(generated_words[0])
