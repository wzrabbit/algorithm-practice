def get_readable_word_count(bit):
    word_count = 0

    for i in range(N):
        success = True

        for j in range(21):
            if bit[j] == "0" and alphabets[j] in words[i]:
                success = False
                break

        if success:
            word_count += 1

    return word_count


words = []

N, K = map(int, input().split())
K -= 5

for _ in range(N):
    words.append(input())

best_word_count = 0
alphabets = "bdefghjklmopqrsuvwxyz"

for i in range(1 << 21):
    bit = bin(i)[2:].zfill(21)

    if bit.count("1") != K:
        continue

    best_word_count = max(best_word_count, get_readable_word_count(bit))

print(best_word_count)
