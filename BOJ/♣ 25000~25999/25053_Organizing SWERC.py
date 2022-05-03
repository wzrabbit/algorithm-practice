import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    quiz = [-1] * 11
    total = 0
    need_more = False

    for _ in range(n):
        b, h = map(int, input().split())
        if b > quiz[h]:
            quiz[h] = b

    for i in range(1, 11):
        if quiz[i] == -1:
            need_more = True
            break
        else:
            total += quiz[i]

    if need_more:
        print('MOREPROBLEMS')
    else:
        print(total)
