group_names = ['PROBRAIN', 'GROW', 'ARGOS', 'ADMIN', 'ANT', 'MOTION', 'SPG', 'COMON', 'ALMIGHTY']

input()
solve_counts = [max(map(int, input().split())) for _ in range(9)]

print(group_names[solve_counts.index(max(solve_counts))])
