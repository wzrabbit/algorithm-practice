N, D, K = map(int, input().split())
state = [0] * N
stars = list(map(int, input().split()))
clean_count = 0

for _ in range(D):
    should_clean = False

    for i in range(N):
        if state[i] + stars[i] > K:
            should_clean = True
            break

    if should_clean:
        state = [0] * N
        clean_count += 1

    for i in range(N):
        state[i] += stars[i]

print(clean_count)
