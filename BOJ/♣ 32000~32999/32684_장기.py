A, B, C, D, E, F = map(int, input().split())
a, b, c, d, e, f = map(int, input().split())

a_score = A * 13 + B * 7 + C * 5 + D * 3 + E * 3 + F * 2
b_score = a * 13 + b * 7 + c * 5 + d * 3 + e * 3 + f * 2 + 1.5

if a_score > b_score:
    print("cocjr0208")
else:
    print("ekwoo")
