import sys
input = sys.stdin.readline


def get_no(a, b):
    if a > b:
        a, b = b, a
    if a == b:
        return -1
    if (a, b) == (1, 2) or (a, b) == (1, 3) or (a, b) == (2, 3):
        return 1
    if (a, b) == (4, 5) or (a, b) == (4, 6) or (a, b) == (5, 6):
        return 2
    if (a, b) == (7, 8) or (a, b) == (7, 9) or (a, b) == (8, 9):
        return 3
    if (a, b) == (1, 4) or (a, b) == (1, 7) or (a, b) == (4, 7):
        return 4
    if ((a, b) == (0, 2) or (a, b) == (0, 5) or (a, b) == (0, 8) or
            (a, b) == (2, 5) or (a, b) == (2, 8) or (a, b) == (5, 8)):
        return 5
    if (a, b) == (3, 6) or (a, b) == (3, 9) or (a, b) == (6, 9):
        return 6
    if (a, b) == (1, 6):
        return 7
    if (a, b) == (1, 5) or (a, b) == (1, 9) or (a, b) == (5, 9):
        return 8
    if (a, b) == (1, 8):
        return 9
    if (a, b) == (0, 1):
        return 10
    if (a, b) == (3, 4):
        return 11
    if (a, b) == (3, 5) or (a, b) == (3, 7) or (a, b) == (5, 7):
        return 12
    if (a, b) == (3, 8):
        return 13
    if (a, b) == (0, 3):
        return 14
    if (a, b) == (2, 4):
        return 15
    if (a, b) == (2, 7):
        return 16
    if (a, b) == (2, 6):
        return 17
    if (a, b) == (2, 9):
        return 18
    if (a, b) == (4, 8):
        return 19
    if (a, b) == (0, 4):
        return 20
    if (a, b) == (6, 8):
        return 21
    if (a, b) == (0, 6):
        return 22
    if (a, b) == (0, 7):
        return 23
    if (a, b) == (0, 9):
        return 24
    if (a, b) == (5, 7):
        return 25
    if (a, b) == (5, 9):
        return 26
    if (a, b) == (4, 9):
        return 27
    if (a, b) == (6, 8):
        return 28


def get_middle_check(a, b):
    if a == 0 or (a > b and b != 0):
        a, b = b, a
    tester = ('_', 2, 5, 8, 0)

    if a not in (2, 5, 8, 0) or b not in (2, 5, 8, 0):
        return (0, 0)
    return (tester.index(a), tester.index(b))


t = int(input())
for _ in range(t):
    phone = list(map(int, list(input().strip())))
    line = set()
    middle_check = [False, False, False, False]

    for i in range(len(phone) - 1):
        current = get_no(phone[i], phone[i + 1])
        if current != -1:
            line.add(current)

        start, end = get_middle_check(phone[i], phone[i + 1])
        for i in range(start, end):
            middle_check[i] = True

    if middle_check[1:] == [True, False, True]:
        line.add(0)

    if 0 <= len(line) <= 3:
        print('EXCELLENT')
    elif len(line) == 4:
        print('GOOD')
    else:
        print('BAD')
