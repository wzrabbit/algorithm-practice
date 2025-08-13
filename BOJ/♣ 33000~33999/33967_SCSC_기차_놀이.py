N = int(input())
cars = input()
answer = 0

for i in range(N - 1):
    if cars[i : i + 2] in ('22', '55'):
        answer += 2
    elif cars[i : i + 2] != '][':
        answer += 1

print(answer)
