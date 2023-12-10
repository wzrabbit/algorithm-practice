N, K = map(int, input().split())
bans = [K % 10, K * 2 % 10]
answer = []

for i in range(1, N + 1):
    if i % 10 not in bans:
        answer.append(i)

print(len(answer))
print(*answer)
