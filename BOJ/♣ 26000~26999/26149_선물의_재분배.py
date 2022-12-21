import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input().split()[0])
before_list = list(map(int, input().split()))
after_list = list(map(int, input().split()))
query_count = 0
queries = []
core_index = after_list.index(max(after_list))

before_list[core_index] = -1
before_list.sort(reverse=True)
for i in range(N):
    if before_list[i] <= 0:
        break
    queries.append(f'+ {core_index + 1} {before_list[i]}')
    query_count += 1

for i in range(N):
    if i != core_index and after_list[i] != 0:
        queries.append(f'+ {i + 1} {after_list[i]}')
        query_count += 1

print(f'{query_count}\n')
print('\n'.join(queries))
