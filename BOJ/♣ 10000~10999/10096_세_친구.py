import sys
input = sys.stdin.readline


def solve():
    if N % 2 == 0:
        print('NOT POSSIBLE')
        return

    al = string[:N // 2]
    ar = string[N // 2:]
    a_fail = 0

    l = 0
    r = 0
    while l < N // 2 and a_fail < 2:
        if al[l] != ar[r]:
            a_fail += 1
            r += 1
        else:
            l += 1
            r += 1

    bl = string[N // 2 + 1:]
    br = string[:N // 2 + 1]
    b_fail = 0

    l = 0
    r = 0
    while l < N // 2 and b_fail < 2:
        if bl[l] != br[r]:
            b_fail += 1
            r += 1
        else:
            l += 1
            r += 1

    if a_fail == 2 and b_fail == 2:
        print('NOT POSSIBLE')
        return

    if a_fail <= 1 and b_fail <= 1:
        if al == bl:
            print(al)
        else:
            print('NOT UNIQUE')
        return

    if a_fail <= 1:
        print(al)
        return

    print(bl)
    return


N = int(input())
string = input().strip()
solve()
