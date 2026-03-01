N, _ = map(int, input().split())
accepted_count = 0

for _ in range(N):
    if '+' in input():
        accepted_count += 1

print(accepted_count)
