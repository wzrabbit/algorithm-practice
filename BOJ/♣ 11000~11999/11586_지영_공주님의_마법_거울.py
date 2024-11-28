N = int(input())
grid = []

for _ in range(N):
    grid.append(input())

Q = int(input())

if Q == 1:
    print('\n'.join(grid))
elif Q == 2:
    for i in range(N):
        print(''.join(grid[i][::-1]))
else:
    print('\n'.join(grid[::-1]))
