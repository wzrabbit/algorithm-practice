import sys
input = sys.stdin.readline
print = sys.stdout.write

test = int(input())
for t in range(1, test + 1):
    n = int(input())
    db = []
    age = {'Ted': 100}

    for _ in range(n):
        db.append(input().strip().split())

    for _ in range(n):
        for i in range(n):
            parent, child, gap = db[i]
            gap = int(gap)

            if db[i][0] in age:
                age[child] = age[parent] - gap

    sorter = list(age.items())
    sorter.sort(key=lambda x: (-x[1], x[0]))

    print('DATASET ' + str(t) + '\n')
    for i in range(len(sorter)):
        if sorter[i][0] != 'Ted':
            print(sorter[i][0] + ' ' + str(sorter[i][1]) + '\n')
