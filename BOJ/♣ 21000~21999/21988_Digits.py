N, D = map(int, input().split())
arr = list(map(int, input().split()))
numbers_by_digit = [[] for _ in range(10)]

for number in arr:
    digit = number % 10
    numbers_by_digit[digit].append(number)

if D == 0:
    if numbers_by_digit[0]:
        print(N)
        print(*arr)
    else:
        print(-1)
    exit()

if D == 5:
    if numbers_by_digit[5]:
        odd_numbers = list(filter(lambda x: x % 2 == 1, arr))
        print(len(odd_numbers))
        print(*odd_numbers)
    else:
        print(-1)
    exit()

for i in range(10):
    numbers_by_digit[i].sort(reverse=True)

candidates = []

for digit in (2, 3, 7, 8):
    if not numbers_by_digit[digit]:
        continue

    repeat = min(len(numbers_by_digit[digit]), len(numbers_by_digit[digit]) % 4 + 4)

    for _ in range(repeat):
        candidates.append(numbers_by_digit[digit].pop())

for digit in (4, 9):
    if not numbers_by_digit[digit]:
        continue

    repeat = min(len(numbers_by_digit[digit]), len(numbers_by_digit[digit]) % 2 + 2)

    for _ in range(repeat):
        candidates.append(numbers_by_digit[digit].pop())

if numbers_by_digit[6]:
    candidates.append(numbers_by_digit[6].pop())

has_odd_number = False
has_even_number = False

for digit in (1, 2, 3, 4, 6, 7, 8, 9):
    if digit % 2 == 1 and numbers_by_digit[digit]:
        has_odd_number = True

    if digit % 2 == 0 and numbers_by_digit[digit]:
        has_even_number = True

C = len(candidates)
dp = [[-1 for _ in range(10)] for _ in range(C + 1)]
prev = [[(-1, -1) for _ in range(10)] for _ in range(C + 1)]
dp[0][1] = 1

for i in range(0, C):
    for j in range(10):
        calc = dp[i][j] * candidates[i]

        if calc > dp[i + 1][calc % 10]:
            dp[i + 1][calc % 10] = calc
            prev[i + 1][calc % 10] = (j, candidates[i])
        
        if dp[i][j] > dp[i + 1][j]:
            dp[i + 1][j] = dp[i][j]
            prev[i + 1][j] = (j, -1)

result_numbers = []
index = D

if dp[C][index] != -1:
    for i in reversed(range(1, C + 1)):
        if prev[i][index][1] != -1:
            result_numbers.append(prev[i][index][1])
        index = prev[i][index][0]

if D == 1 and not result_numbers and not has_odd_number:
    print(-1)
    exit()

if D == 6 and not result_numbers and not has_even_number:
    print(-1)
    exit()

if D not in (1, 6) and not result_numbers:
    print(-1)
    exit()

answer_length = len(result_numbers)

for digit in (1, 2, 3, 4, 6, 7, 8, 9):
    if numbers_by_digit[digit] and (D % 2 == 0 or digit % 2 == 1):
        answer_length += len(numbers_by_digit[digit])

print(answer_length)

for digit in (1, 2, 3, 4, 6, 7, 8, 9):
    if numbers_by_digit[digit] and (D % 2 == 0 or digit % 2 == 1):
        print(*numbers_by_digit[digit], end=' ')

print(*result_numbers)
