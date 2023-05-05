numbers = sorted(list(map(int, input().split())))
print(numbers[0], numbers[1], end=' ')

if numbers[2] == numbers[0] + numbers[1]:
    print(numbers[3])
else:
    print(numbers[2])
