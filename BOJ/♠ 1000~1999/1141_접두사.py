N = int(input())
words = []
size = 1

for _ in range(N):
    words.append(input().strip())

words.sort(key=lambda x: len(x))

for i in range(N - 1):
    conflict = False

    for j in range(i + 1, N):
        if words[i] == words[j][: len(words[i])]:
            conflict = True
            break

    if not conflict:
        size += 1

print(size)
