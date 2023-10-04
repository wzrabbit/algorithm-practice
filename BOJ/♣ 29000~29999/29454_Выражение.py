N = int(input())
numbers = list(map(int, input().split()))
numbers_sum = sum(numbers)

for i in range(N):
    if numbers[i] * 2 == numbers_sum:
        print(i + 1)
        break
