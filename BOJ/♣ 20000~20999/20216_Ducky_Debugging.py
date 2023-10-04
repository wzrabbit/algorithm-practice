import sys

input = sys.stdin.readline
print = sys.stdout.write
flush = sys.stdout.flush

while True:
    mark = input().strip()[-1]

    if mark == ".":
        print("*Nod*\n")
        flush()
    elif mark == "?":
        print("Quack!\n")
        flush()
    else:
        break
