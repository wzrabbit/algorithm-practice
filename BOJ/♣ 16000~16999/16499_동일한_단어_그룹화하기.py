N = int(input())
group = set()

for i in range(N):
    cur = input()
    group.add("".join(sorted(cur)))

print(len(group))
