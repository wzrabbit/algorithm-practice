import sys

print = sys.stdout.write

N = int(input())

for i in range(1, N + 1, 2):
    print(f"{i} ")

for i in reversed(range(2, N + 1, 2)):
    print(f"{i} ")
