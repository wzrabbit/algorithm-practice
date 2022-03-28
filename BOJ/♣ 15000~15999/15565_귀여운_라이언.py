import sys
input = sys.stdin.readline
length, need = map(int, input().split(' '))
dolls = list(map(int, input().split(' ')))
current = -dolls[0] + 2
min_ = 10 ** 7
start, end = 0, 0

while True:
    if current == need and end - start + 1 < min_:
        min_ = end - start + 1

    if end == length - 1 and start == end:
        break

    if (current < need or start == end) and end < length - 1:
        end += 1
        if dolls[end] == 1:
            current += 1
    else:
        if dolls[start] == 1:
            current -= 1
        start += 1

if min_ == 10 ** 7:
    print(-1)
else:
    print(min_)
