import sys
input = sys.stdin.readline
debug = print
print = sys.stdout.write

R, C = map(int, input().split())
one_count, nine_count = map(int, input().split())
triangle = R * (R - 1) // 2

if nine_count < triangle or one_count < triangle:
    print("-1")
    exit()

arr = [i for i in range(R)]
nine_count -= R * (R - 1) // 2

limit = C - R + 1

for i in range(R - 1, -1, -1):
    if nine_count == 0:
        break

    matched = min(nine_count, limit)
    nine_count -= matched
    arr[i] += matched

for i in range(R):
    print("9 " * arr[i] + "1 " * (C - arr[i]) + "\n")
