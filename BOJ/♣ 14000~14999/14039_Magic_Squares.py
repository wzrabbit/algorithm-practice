matrix = []

for _ in range(4):
    matrix.append(list(map(int, input().split())))

row_sum = sum(matrix[0])
col_sum = matrix[0][0] + matrix[1][0] + matrix[2][0] + matrix[3][0]
is_magic = True

for r in range(1, 4):
    if sum(matrix[r]) != row_sum:
        is_magic = False
        break

for c in range(1, 4):
    if matrix[0][c] + matrix[1][c] + matrix[2][c] + matrix[3][c] != col_sum:
        is_magic = False
        break

if is_magic:
    print('magic')
else:
    print('not magic')
