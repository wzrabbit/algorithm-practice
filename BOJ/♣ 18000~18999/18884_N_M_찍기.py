import sys

print = sys.stdout.write

R, C = map(int, input().split())

for r in range(R):
    for c in range(C):
        print(f"{r * C + c + 1}")

        if c != C - 1:
            print(" ")

    print("\n")
