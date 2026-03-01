S = input()
has_even = False
has_odd = False

for i in range(26):
    cur_count = S.count(chr(97 + i))
    if cur_count == 0:
        continue

    if cur_count % 2 == 0:
        has_even = True
    else:
        has_odd = True

if has_even and has_odd:
    print('0/1')
elif has_even:
    print(0)
else:
    print(1)
