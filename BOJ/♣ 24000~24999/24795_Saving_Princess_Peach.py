N, Y = map(int, input().split())
obstacles = set(int(input()) for _ in range(Y))

for i in range(N):
    if i not in obstacles:
        print(i)

print(f'Mario got {len(obstacles)} of the dangerous obstacles.')
