text = list(input())
cnt = 1

for i in range(len(text)):
    text[i] = ord(text[i])

for i in range(1, len(text)):
    if text[i] > text[i - 1]:
        cnt += 1

print(cnt)
