A, B, K, M = map(int, input().split())
start = 10 ** (K - 1)
end = int('9' * K)
answer = 0

for i in range(start, end + 1):
    cur_cycle = (str(i) * 13)[:13]

    for j in range(K, 13):
        cur_number = int(cur_cycle[:j])
        if cur_number % M == 0 and A <= cur_number <= B:
            answer += 1

print(answer)
