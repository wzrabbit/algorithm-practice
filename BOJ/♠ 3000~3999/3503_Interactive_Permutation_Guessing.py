import sys

input = sys.stdin.readline
print = sys.stdout.write
flush = sys.stdout.flush

N = int(input())
permutation = []
lcs = -1

for i in range(1, N + 1):
    permutation.append(i)

for i in range(1, N + 1):
    for j in range(N):
        backup = permutation[:]
        permutation.remove(i)
        permutation.insert(j, i)

        for k in range(N):
            print(f"{permutation[k]} ")
        print("\n")
        flush()

        cur_lcs = int(input())

        if cur_lcs == N:
            exit()

        if cur_lcs > lcs and lcs != -1:
            lcs = cur_lcs
            break

        if cur_lcs < lcs:
            permutation = backup[:]
            break

        if lcs == -1:
            lcs = cur_lcs
