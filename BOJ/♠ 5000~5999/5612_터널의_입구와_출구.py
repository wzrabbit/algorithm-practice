N = int(input())
best_count = int(input())
cur_count = best_count

for _ in range(N):
    plus, minus = map(int, input().split())
    cur_count += plus - minus
    best_count = max(best_count, cur_count)

    if cur_count < 0:
        print(0)
        exit()

print(best_count)
