import sys
input = sys.stdin.readline

N = int(input())
words = [input().strip() for _ in range(N)]
words.sort()

max_length = 0

for i in range(N - 1):
    x = words[i]
    y = words[i + 1]
    cur_length = 0

    for j in range(min(len(x), len(y))):
        if x[j] != x[j]:
            break
        cur_length += 1

    max_length = max(max_length, cur_length)

print(max_length)
