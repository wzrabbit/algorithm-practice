import sys
input = sys.stdin.readline
print = sys.stdout.write

Q = int(input())
for _ in range(Q):
    x, y = map(int, input().split())
    moves = 0
    while x != y:
        if x > y:
            x //= 2
        else:
            y //= 2
        moves += 1

    print(f'{moves}\n')
