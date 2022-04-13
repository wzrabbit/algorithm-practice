import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
arr = list(map(int, input().split()))
zero = []
one = []
two = []

for d in arr:
    if d % 3 == 0:
        zero.append(str(d))
    elif d % 3 == 1:
        one.append(str(d))
    else:
        two.append(str(d))

zero_cnt = len(zero)
one_cnt = len(one)
two_cnt = len(two)

if (
    n % 2 == 1 and zero_cnt > one_cnt + two_cnt + 1 or
    n % 2 == 0 and zero_cnt > one_cnt + two_cnt or
    one_cnt > 0 and two_cnt > 0 and zero_cnt == 0
):
    print('-1')
else:
    idx = 0
    while idx < n:
        if idx == 0 and n % 2 == 1 and zero_cnt == one_cnt + two_cnt + 1:
            print(zero.pop() + ' ')
            zero_cnt -= 1
            idx += 1
        elif one_cnt > 0:
            print(one.pop() + ' ')
            one_cnt -= 1
            idx += 1
            if zero_cnt > one_cnt:
                print(zero.pop() + ' ')
                zero_cnt -= 1
                idx += 1
        else:
            print(two.pop() + ' ')
            two_cnt -= 1
            idx += 1
            if zero_cnt > two_cnt:
                print(zero.pop() + ' ')
                zero_cnt -= 1
                idx += 1
