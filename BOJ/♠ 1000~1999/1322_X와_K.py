N, K = map(int, input().split())
bit = list(bin(N)[2:].zfill(64))
zero_bit_no = [-1] * 64
cur_no = 0
one_count = bit.count("1")
Y = 0

for i in reversed(range(64)):
    if bit[i] == "0":
        zero_bit_no[i] = cur_no
        cur_no += 1

for i in range(64):
    if zero_bit_no[i] == -1:
        continue

    if K >= 2 ** zero_bit_no[i]:
        Y += 2 ** (63 - i)
        K -= 2 ** zero_bit_no[i]

print(Y)
