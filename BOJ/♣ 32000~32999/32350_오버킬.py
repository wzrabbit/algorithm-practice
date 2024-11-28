N, D, P = map(int, input().split())
hp = list(map(int, input().split()))
answer = 0
cur = 0

while cur < N:
    if hp[cur] <= 0:
        cur += 1
        continue

    hp[cur] -= D
    answer += 1

    if hp[cur] <= 0:
        if cur == N - 1:
            break

        hp[cur + 1] -= -hp[cur] * P // 100
        cur += 1

print(answer)
