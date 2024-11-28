N = int(input())
rules = []

for _ in range(N):
    rule = input()
    rules.append(rule)

Q = int(input())

for _ in range(Q):
    q = int(input())

    if 1 <= q <= N:
        print(f'Rule {q}: {rules[q - 1]}')
    else:
        print(f'Rule {q}: No such rule')
