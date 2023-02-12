start, end = map(int, input().split())
queries = []

one_num = 1

while start % 9 != one_num % 9 or one_num < start:
    one_num = one_num * 10 + 1

if one_num != start:
    queries.append(f'+ {(one_num - start) // 9}')

queries.append(f'- {len(str(one_num))}')
start = 0

while start % 9 != end % 9:
    if start == 0:
        queries.append('+ 2')
    else:
        queries.append('+ 1')
        
    queries.append('- 1')
    start = (start + 8) % 9
    
if start != end:
    queries.append(f'+ {(end - start) // 9}')

print('Stable')
print(len(queries))
print('\n'.join(queries))