import sys
input = sys.stdin.readline

N = int(input())
grid = []
for _ in range(N):
    grid.append(list(input().strip()))
    
top_pos = 10e10
bottom_pos = -10e10
left_pos = 10e10
right_pos = -10e10

for r in range(N):
    for c in range(N):
        if grid[r][c] == 'G':
            top_pos = min(top_pos, r)
            bottom_pos = max(bottom_pos, r)
            left_pos = min(left_pos, c)
            right_pos = max(right_pos, c)

result = bottom_pos - top_pos + right_pos - left_pos
if abs(bottom_pos - top_pos) > 0:
    result += min(top_pos, N - bottom_pos - 1)
if abs(right_pos - left_pos) > 0:
    result += min(left_pos, N - right_pos - 1)

print(result)