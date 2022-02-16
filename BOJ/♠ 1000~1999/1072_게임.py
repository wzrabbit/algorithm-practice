import sys
input = sys.stdin.readline
game, win = list(map(int, input().split()))
start, end = 1, 1000000000
before = win * 100 // game

if (win + end) * 100 // (game + end) == before:
    print(-1)
else:
    while start <= end:
        mid = (start + end) // 2
        if (win + mid) * 100 // (game + mid) > before:
            end = mid - 1
        else:
            start = mid + 1
    print(start)