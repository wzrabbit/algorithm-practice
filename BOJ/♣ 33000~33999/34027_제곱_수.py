squares = set()

for i in range(1, 10 ** 5):
    squares.add(i * i)

T = int(input())

for _ in range(T):
    N = int(input())

    if N in squares:
        print(1)
    else:
        print(0)
