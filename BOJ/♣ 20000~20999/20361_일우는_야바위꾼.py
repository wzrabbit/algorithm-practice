import sys
input = sys.stdin.readline

_, X, Q = map(int, input().split())
answer = X

for _ in range(Q):
    A, B = map(int, input().split())

    if A == answer:
        answer = B
        continue

    if B == answer:
        answer = A
        continue

print(answer)
