numbers = list(map(int, input().split()))
result = 0

for i in range(9):
    for j in range(i + 1, 10):
        result ^= numbers[i] | numbers[j]

for i in range(8):
    for j in range(i + 1, 9):
        for k in range(j + 1, 10):
            result ^= numbers[i] | numbers[j] | numbers[k]

print(result)
