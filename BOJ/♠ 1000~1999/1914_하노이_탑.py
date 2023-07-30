import sys

print = sys.stdout.write


def top_down(N, a, b, c):
    if N == 1:
        print(f"{a} {c}\n")
        return

    top_down(N - 1, a, c, b)
    top_down(1, a, b, c)
    top_down(N - 1, b, a, c)


N = int(input())
print(f"{2 ** N - 1}\n")

if N <= 20:
    top_down(20, 1, 2, 3)
