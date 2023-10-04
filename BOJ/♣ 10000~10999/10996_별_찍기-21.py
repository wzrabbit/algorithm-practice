import sys

print = sys.stdout.write

N = int(input())

for r in range(N * 2):
    for c in range(N):
        if (r + c) % 2 == 0:
            print("*")
        else:
            print(" ")
    print("\n")
