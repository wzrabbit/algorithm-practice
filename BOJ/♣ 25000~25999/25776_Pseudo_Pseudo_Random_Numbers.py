N, K = map(int, input().split())
zero_string = "0" * (K + 1)
one_string = "1" * (K + 1)
answer_count = 0

for i in range(0, 1 << N):
    binary = bin(i)[2:].zfill(N)
    if zero_string not in binary and one_string not in binary:
        answer_count += 1

print(answer_count)
