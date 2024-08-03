Q = int(input())
answer = 1

for _ in range(Q):
    a, b = map(int, input().split())

    if a == answer:
        answer = b
        continue

    if b == answer:
        answer = a
        continue

print(answer)
