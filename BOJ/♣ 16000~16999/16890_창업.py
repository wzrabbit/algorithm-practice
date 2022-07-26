import sys
input = sys.stdin.readline
print = sys.stdout.write

A = list(input().strip())
B = list(input().strip())
N = len(A)
is_A_turn = True

A.sort()
B.sort(reverse=True)

l = 0
r = N - 1
al = 0
ar = (N - 1) // 2
bl = 0
br = (N - 2) // 2
company = [''] * N

while l <= r:
    if is_A_turn:
        if A[al] < B[bl]:
            company[l] = A[al]
            l += 1
            al += 1
        else:
            company[r] = A[ar]
            r -= 1
            ar -= 1
    else:
        if B[bl] > A[al]:
            company[l] = B[bl]
            l += 1
            bl += 1
        else:
            company[r] = B[br]
            r -= 1
            br -= 1

    is_A_turn = not is_A_turn

print(''.join(company))
