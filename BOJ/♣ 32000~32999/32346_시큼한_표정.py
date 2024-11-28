def get_inverse(x, y):
    if y == 1:
        return x % MOD
    
    prev = get_inverse(x, y // 2)

    if y % 2 == 1:
        return prev * prev % MOD * x % MOD
    
    return prev * prev % MOD

MOD = 1000000007

N = int(input())
S = input()

sour_ranges = []
factorial = [1]
cur_value = 1

for i in range(1, N + 1):
    factorial.append(cur_value * i % MOD)
    cur_value = (cur_value * i) % MOD

for i in range(N):
    if S[i:i+2] != "><":
        continue

    start = i
    end = i + 1

    while True:
        if start < 0 or end >= N:
            break

        if S[start] != ">" or S[end] != "<":
            break

        sour_ranges.append((start, end))
        start -= 1
        end += 1

answer = 0

for (start, end) in sour_ranges:
    left = start
    right = N - end - 1
    cur_answer = factorial[left + right] * get_inverse(factorial[left], MOD - 2) % MOD * get_inverse(factorial[right], MOD - 2) % MOD
    answer = (answer + cur_answer) % MOD

print(answer)

