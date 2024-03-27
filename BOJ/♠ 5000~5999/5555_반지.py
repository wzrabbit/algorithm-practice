pattern = input()
answer = 0

N = int(input())

for _ in range(N):
    ring = input() * 2

    if pattern in ring:
        answer += 1

print(answer)
