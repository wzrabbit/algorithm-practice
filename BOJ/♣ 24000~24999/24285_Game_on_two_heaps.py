def get_gcd(a, b):
    if b == 0:
        return a
    else:
        return get_gcd(b, a % b)


A, B = map(int, input().split())
if A > B:
    A, B = B, A

div = get_gcd(A, B)
C = A // div
D = B // div

answer = D // C
if D % C == 0:
    answer -= 1

print(min(answer, A // D))
