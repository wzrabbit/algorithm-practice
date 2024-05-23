A, B, C, D = map(int, input().split())

if A > B:
    A, B = B, A

if C > D:
    C, D = D, C

if A > C:
    A, B, C, D = C, D, A, B

answer = max(B, D) - A + 1

if B + 1 < C:
    answer -= C - B - 1

print(answer)
