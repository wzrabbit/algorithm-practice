import sys
input = sys.stdin.readline

n = int(input())
zero_one = 0
one_zero = 0
zero = 0
one = 0
changed = 0

for _ in range(n):
    bundle = list(input().strip())
    first, last = bundle[0], bundle[-1]

    if first == '0' and last == '0':
        zero += 1
    elif first == '1' and last == '1':
        one += 1
    elif first == '0' and last == '1':
        zero_one += 1
    else:
        one_zero += 1

    for i in range(1, len(bundle)):
        if bundle[i - 1] != bundle[i]:
            changed += 1

if zero > 0 and one > 0 and zero_one + one_zero == 0:
    changed += 1
changed += max(abs(one_zero - zero_one) - 1, 0)

print(changed)
