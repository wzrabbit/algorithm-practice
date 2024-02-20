def has_duplicates(num):
    str_num = str(num)

    for i in range(1, 10):
        if str_num.count(str(i)) > 1:
            return True

    return False


def find_higher_number(num):
    if num >= 987_654_321:
        return 0

    if num <= 8:
        return num + 1

    str_num = str(num)
    digit_size = len(str_num)

    for i in reversed(range(1, digit_size)):
        cur = str_num[:i]

        for j in range(int(str_num[i]) + 1, 10):
            if str(j) not in cur:
                cur += str(j)
                break

        for j in range(digit_size - i - 1):
            for k in range(1, 10):
                if str(k) not in cur:
                    cur += str(k)
                    break

        if not has_duplicates(int(cur)) and int(cur) > num and cur.count("0") == 0:
            return int(cur)

    cur = ""

    for i in range(1, digit_size + 2):
        cur += str(i)

    return int(cur)


while True:
    try:
        N = int(input())
        print(find_higher_number(N))
    except EOFError:
        break
