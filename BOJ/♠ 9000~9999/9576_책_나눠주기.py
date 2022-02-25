import sys
input = sys.stdin.readline
print = sys.stdout.write
case = int(input())
for i in range(case):
    total = 0
    book, pupil = list(map(int, input().split()))
    book = [False for i in range(book + 1)]
    order = []
    for j in range(pupil):
        order.append(list(map(int, input().split())))
    order.sort(key=lambda x: x[1] * 10000 + x[0])

    for i in range(pupil):
        for j in range(1, len(book)):
            if j >= order[i][0] and j <= order[i][1] and book[j] == False:
                total += 1
                book[j] = True
                break

    print(str(total) + '\n')
