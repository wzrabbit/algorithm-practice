N = int(input())
print('int a;')
print('int *ptr = &a;')

if N >= 2:
    print('int **ptr2 = &ptr;')

for i in range(3, N + 1):
    print(f'int {"*" * i}ptr{i} = &ptr{i - 1};')
