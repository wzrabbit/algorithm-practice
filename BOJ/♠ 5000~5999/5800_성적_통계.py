import sys
input = sys.stdin.readline
print = sys.stdout.write

case = int(input())
for i in range(case):
    score = list(map(int, input().split()))
    score[0] = 999
    score.sort()
    score.pop()

    max_ = score[-1]
    min_ = score[0]
    gap = 0
    for j in range(len(score) - 1):
        if score[j + 1] - score[j] > gap:
            gap = score[j + 1] - score[j]

    print('Class {}\nMax {}, Min {}, Largest gap {}\n'.format(i + 1, max_, min_, gap))