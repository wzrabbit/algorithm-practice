import sys
input = sys.stdin.readline
length = int(input())
word = input().strip()
table = [0] * length

l = 0
r = 1
for i in range(1, len(word)):
    if word[l] == word[r]:
        table[i] = table[i - 1] + 1
        l += 1
    else:
        while True:
            if l == 0:
                table[i] = 0
                break
            else:
                l = table[l - 1]
                if word[l] == word[r]:
                    table[i] = l + 1
                    l += 1
                    break
    r += 1

print(len(word) - table[-1])
