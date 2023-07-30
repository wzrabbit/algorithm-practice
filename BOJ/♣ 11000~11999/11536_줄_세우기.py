N = int(input())
names = []

for _ in range(N):
    names.append(input())

increasing_names = sorted(names)
decreasing_names = sorted(names, reverse=True)

if names == increasing_names:
    print("INCREASING")
elif names == decreasing_names:
    print("DECREASING")
else:
    print("NEITHER")
