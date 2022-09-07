import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())
for _ in range(T):
    A = 0
    B = 0

    N = int(input())
    for __ in range(N):
        game = input().rstrip()
        if game in ('R S', 'S P', 'P R'):
            A += 1
        elif game in ('S R', 'P S', 'R P'):
            B += 1

    if A > B:
        print('Player 1\n')
    elif A < B:
        print('Player 2\n')
    else:
        print('TIE\n')
