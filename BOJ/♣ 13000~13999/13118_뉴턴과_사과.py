points = list(map(int, input().split()))
x = int(input().split()[0])

for i in range(4):
    if points[i] == x:
        print(i + 1)
        exit()

print(0)
