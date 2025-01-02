import sys
input = sys.stdin.readline
print = sys.stdout.write

while True:
    B, N = map(int, input().split())

    if B == N == 0:
        break

    best_A = 0
    best_gap = 1000000

    for i in range(1, 1000001):
        calc = i ** N
        gap = abs(B - calc)

        if gap < best_gap:
            best_A = i
            best_gap = gap

        if calc > 1000000:
            break

    print(f'{best_A}\n')
