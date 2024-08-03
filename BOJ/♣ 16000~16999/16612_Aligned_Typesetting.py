import sys
input = sys.stdin.readline

N, L = map(int, input().split())
word_length = 0

for _ in range(N):
    word_length += len(input().strip())

if N == 1:
    if L == word_length:
        print('Yes')
    else:
        print('No')

    exit()

if L != word_length and L > word_length and (L - word_length) % (N - 1) == 0:
    print('Yes')
else:
    print('No')
