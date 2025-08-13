N = int(input())

print(" " * (N - 1) + "*")

if N == 1:
    exit()

for i in range(N - 2):
    print(" " * (N - 2 - i) + "*" + " " * (1 + 2 * i) + "*")

print("*" * (2 * N - 1))
