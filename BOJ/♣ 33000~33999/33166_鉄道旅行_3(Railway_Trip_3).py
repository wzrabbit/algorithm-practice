P, Q = map(int, input().split())
A, B = map(int, input().split())

print(min(P, Q) * A + max(0, Q - P) * B)
