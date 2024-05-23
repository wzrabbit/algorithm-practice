N = int(input())
answer = 0

for i in range(N):
    a, b, c = map(int, input().split())

    if a == -1:
        continue

    if b == -1 and c != -1:
        continue

    if a > b and b != -1:
        continue

    if b > c and c != -1:
        continue

    answer += 1

print(answer)
