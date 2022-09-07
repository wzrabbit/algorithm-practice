import sys
input = sys.stdin.readline

for _ in range(3):
    N = int(input())
    sum_ = 0

    for _ in range(N):
        sum_ += int(input())

    if sum_ > 0:
        print('+')
    elif sum_ < 0:
        print('-')
    else:
        print('0')
