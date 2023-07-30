N = int(input())
total = 0

for i in range(N + 1):
    for j in range(i + 1):
        total += i + j

print(total)
