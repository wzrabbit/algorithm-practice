import sys
cases = int(sys.stdin.readline())

for _ in range(cases):
    length = int(sys.stdin.readline())
    stock = list(map(int, sys.stdin.readline().split(' ')))
    max_ = 0
    total = 0

    for i in reversed(range(length)):
        if stock[i] > max_:
            max_ = stock[i]
        else:
            total += max_ - stock[i]

    print(total)
