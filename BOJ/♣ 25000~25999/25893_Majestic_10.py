N = int(input())

for _ in range(N):
    line = input()
    stats = list(map(int, line.split()))
    count = sum(1 for s in stats if s >= 10)

    print(line)
    print(["zilch", "double", "double-double", "triple-double"][count])
    print()
