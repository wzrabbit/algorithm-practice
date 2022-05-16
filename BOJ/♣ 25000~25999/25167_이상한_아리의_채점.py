import sys
import functools
input = sys.stdin.readline


def compare(a, b):
    if a[1] != b[1]:
        return a[1] - b[1]

    if a[0] < b[0]:
        return -1
    else:
        return 1


q, p, l = map(int, input().split())
player = list(input().strip().split())
time = {}
solve = {}
score = {}
for i in range(p):
    time[player[i]] = [0] * (q + 1)
    solve[player[i]] = [-1] * (q + 1)
    score[player[i]] = 0

for i in range(l):
    no, tim, name, verdict = input().strip().split()
    no = int(no)
    h, m = tim.split(':')
    h = int(h)
    m = int(m)
    tim = h * 60 + m

    if verdict == 'wrong':
        if solve[name][no] == -1:
            time[name][no] = tim
            solve[name][no] = 0
    else:
        if solve[name][no] == -1:
            solve[name][no] = 2
        elif solve[name][no] == 0:
            time[name][no] = tim - time[name][no]
            solve[name][no] = 1

for i in range(1, q + 1):
    sorter = []
    for j in range(p):
        if solve[player[j]][i] == 1:
            sorter.append((player[j], time[player[j]][no]))
        elif solve[player[j]][i] == 0:
            score[player[j]] += p
        else:
            score[player[j]] += p + 1

    sorter.sort(key=functools.cmp_to_key(compare))
    for j in range(len(sorter)):
        score[sorter[j][0]] += j + 1

sorter = []
for i in range(p):
    sorter.append((player[i], score[player[i]]))
sorter.sort(key=functools.cmp_to_key(compare))
for i in range(p):
    print(sorter[i][0])
