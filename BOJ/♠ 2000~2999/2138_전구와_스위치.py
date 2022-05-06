import sys
input = sys.stdin.readline


def toggle(old):
    if old == '1':
        return '0'
    else:
        return '1'


n = int(input())
before = list(input().strip())
before2 = before[:]
after = list(input().strip())
cnt = 0
cnt2 = 1
min_ = 999999

before2[0] = toggle(before2[0])
before2[1] = toggle(before2[1])

for i in range(1, n):
    if before[i - 1] != after[i - 1]:
        before[i - 1] = toggle(before[i - 1])
        before[i] = toggle(before[i])
        if i != n - 1:
            before[i + 1] = toggle(before[i + 1])
        cnt += 1

for i in range(1, n):
    if before2[i - 1] != after[i - 1]:
        before2[i - 1] = toggle(before2[i - 1])
        before2[i] = toggle(before2[i])
        if i != n - 1:
            before2[i + 1] = toggle(before2[i + 1])
        cnt2 += 1

if before[-1] == after[-1]:
    min_ = cnt

if before2[-1] == after[-1]:
    min_ = min(min_, cnt2)

if min_ == 999999:
    print(-1)
else:
    print(min_)
