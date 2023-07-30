N = int(input())
K = int(input())
words = []
words_set = set()

for i in range(N):
    words.append(input())

if K == 2:
    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            words_set.add(words[i] + words[j])

if K == 3:
    for i in range(N):
        for j in range(N):
            for k in range(N):
                if i == j or j == k or i == k:
                    continue
                words_set.add(words[i] + words[j] + words[k])

if K == 4:
    for i in range(N):
        for j in range(N):
            for k in range(N):
                for l in range(N):
                    if i in (j, k, l) or j in (k, l) or k == l:
                        continue
                    words_set.add(words[i] + words[j] + words[k] + words[l])

print(len(words_set))
