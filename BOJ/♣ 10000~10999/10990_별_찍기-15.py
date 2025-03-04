N = int(input())

for i in range(N):
    print(" " * (N - i - 1) + "*" + " " * max(0, i * 2 - 1), end="")

    if i != 0:
        print("*", end="")
    
    print()
