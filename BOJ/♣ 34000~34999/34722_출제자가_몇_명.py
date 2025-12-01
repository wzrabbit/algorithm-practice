N = int(input())
success_count = 0

for _ in range(N):
    S, C, A, R = map(int, input().split())

    if S >= 1000 or C >= 1600 or A >= 1500 or (R != -1 and R <= 30):
        success_count += 1

print(success_count)
