import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    A, B = map(int, input().split())
    target = "B"

    if A > B:
        A, B = B, A
        target = "A"

    if (B - A) % 2 == 1:
        print("-1\n")
        continue

    x = 0
    success = True
    cur_A = A

    for i in range(31):
        if (cur_A & (1 << i)) == (B & (1 << i)):
            continue

        if (cur_A & (1 << (i - 1))) == 0:
            success = False
            break

        x |= 1 << (i - 1)
        cur_A = (cur_A + (1 << (i - 1))) ^ (1 << (i - 1))

    if success:
        print("1\n")
        print(f"{target} {x}\n")
        continue

    print("2\n")
    print(f"{target} {(B - A) // 2}\n")
    print(f"{target} {(B - A) // 2}\n")
