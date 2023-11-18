N = int(input())

if N % 2 == 1:
    print("7", end="")
    N -= 3

print("1" * (N // 2))
