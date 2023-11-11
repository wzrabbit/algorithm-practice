visited = set()
paths = []

for i in range(36):
    paths.append(input())

paths.append(paths[0])

for i in range(36):
    prev = paths[i]
    cur = paths[i + 1]

    if cur in visited:
        print("Invalid")
        exit()

    r_diff = abs(int(cur[1]) - int(prev[1]))
    c_diff = abs(ord(cur[0]) - ord(prev[0]))

    if (r_diff, c_diff) != (1, 2) and (r_diff, c_diff) != (2, 1):
        print("Invalid")
        exit()

    visited.add(cur)

print("Valid")
