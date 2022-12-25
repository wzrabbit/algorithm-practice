N = int(input())

result = [
    max(N, min(N + 8, 210)),
    max(N, min(N + 4, 220)),
    max(N, min(N + 2, 230)),
    N + 1
]

ans = ''
ans_level = N
for i in range(4):
    if result[i] >= ans_level:
        ans = i + 1
        ans_level = result[i]

print(ans)
