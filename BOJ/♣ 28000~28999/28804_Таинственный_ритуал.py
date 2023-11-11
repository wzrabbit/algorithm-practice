import sys

input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    N = int(input())

    for i in range(1, 10):
        X = N

        while X < i:
            if X % 10 == 0:
                X //= 10
            else:
                if i == 5 and X % 10 != 5:
                    break
                X += i

        if X == i:
            print(f"{i}\n")
            break
