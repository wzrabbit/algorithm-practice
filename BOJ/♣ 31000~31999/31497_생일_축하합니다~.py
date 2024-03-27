import sys

input = sys.stdin.readline
print = sys.stdout.write
flush = sys.stdout.flush

N = int(input())
handles = []
has_lied = False

for _ in range(N):
    cur = input().strip()
    handles.append(cur)

for i in range(N):
    correct_count = 0

    if i == N - 1:
        print(f"! {handles[i]}\n")
        flush()
        exit()

    if has_lied:
        print(f"? {handles[i]}\n")
        flush()

        result = int(input())

        if result == 1:
            print(f"! {handles[i]}\n")
            exit()

        continue

    for _ in range(2):
        print(f"? {handles[i]}\n")
        flush()

        result = int(input())
        correct_count += result

    if correct_count == 0:
        continue

    if correct_count == 1:
        has_lied = True

        print(f"? {handles[i]}\n")
        flush()

        result = int(input())

        if result == 1:
            print(f"! {handles[i]}\n")
            exit()

        continue

    if correct_count == 2:
        print(f"! {handles[i]}\n")
        exit()
