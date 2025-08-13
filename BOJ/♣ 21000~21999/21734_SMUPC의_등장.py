S = input()

for cur in S:
    ascii_digit_sum = sum(map(int, list(str(ord(cur)))))
    print(cur * ascii_digit_sum)
