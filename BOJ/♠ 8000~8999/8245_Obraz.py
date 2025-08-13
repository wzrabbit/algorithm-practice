R, C = map(int, input().split())
original = []
answer = [[None] * R for _ in range(C)]

for _ in range(R):
    original.append(input())

for r in range(C):
    for c in range(R):
        answer[r][c] = original[R - c - 1][r]

for r in range(C):
    print(''.join(answer[r]))
