import sys

input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    A, B, K = map(int, input().split())

    if A >= 100 and B >= 100 and K == 1:
        print("0\n")
        continue

    matched = max(0, min(A, B) - 100)
    success = False
    answer = matched
    A -= matched
    B -= matched

    while A > 0 and B > 0:
        cur_A = min(A, 99)
        cur_B = min(B, 99)

        if cur_A * K == cur_B or cur_B * K == cur_A:
            print(f"{answer}\n")
            success = True
            break

        answer += 1
        A -= 1
        B -= 1

    if not success:
        print("-1\n")
