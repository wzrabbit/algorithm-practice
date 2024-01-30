N = int(input())
answer = 0

for i in range(1, N + 1):
    digits = list(map(int, list(str(i))))
    digit_sum = sum(digits)

    if i % digit_sum == 0:
        answer += 1

print(answer)
