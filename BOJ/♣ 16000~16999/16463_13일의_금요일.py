year = int(input())
limit = [0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
cnt = 0
y = 2019
m = 1
d = 4
rem = 0


def is_yoon(year):
    if year % 400 == 0:
        return True
    if year % 400 != 0 and year % 100 == 0:
        return False
    if year % 100 != 0 and year % 4 == 0:
        return True
    return False


while y <= year:
    if d == 13:
        cnt += 1

    d += 7
    if m == 2:
        if is_yoon(y):
            if d > 29:
                m = 3
                d -= 29
        else:
            if d > 28:
                m = 3
                d -= 28
    else:
        if d > limit[m]:
            d -= limit[m]
            m += 1

    if m == 13:
        y += 1
        m = 1

print(cnt)
