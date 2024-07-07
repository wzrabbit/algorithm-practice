N, T = map(int, input().split())
answer = -1

for i in range(N):
    start, duration = map(int, input().split())

    if start + duration <= T:
        answer = max(answer, start)

print(answer)
