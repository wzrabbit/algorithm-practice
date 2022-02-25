import sys
input = sys.stdin.readline

union = []
rank = []
blue = []
red = []


def getParent(a):
    if union[a] == 0:
        return a
    union[a] = getParent(union[a])
    return union[a]


def merge(a, b):
    a = getParent(a)
    b = getParent(b)
    if a != b:
        if rank[a] > rank[b]:
            union[b] = a
            rank[a] += rank[b]
        else:
            union[a] = b
            rank[b] += rank[a]
        return True
    else:
        return False


def clearUnion(a):
    global union, rank
    union = [0 for i in range(a + 1)]
    rank = [1 for i in range(a + 1)]


def clearAll(a):
    global union, rank, blue, red
    union = [0 for i in range(a + 1)]
    rank = [1 for i in range(a + 1)]
    blue = []
    red = []


def check(mode, vertex):
    global blue, red
    count = 0

    if mode == 'max':
        for i in blue:
            a, b = i
            if merge(a, b):
                count += 1
            if count == vertex - 1:
                return count
        return count
    else:
        for i in red:
            a, b = i
            if merge(a, b):
                count += 1
            if count == vertex - 1:
                return 0
        return vertex - 1 - count


while True:
    vertex, edge, goal = list(map(int, input().split()))
    if vertex == edge == goal == 0:
        break
    clearAll(vertex)

    for i in range(edge):
        c, a, b = list(map(str, input().split()))
        if c == 'B':
            blue.append((int(a), int(b)))
        else:
            red.append((int(a), int(b)))

    min_ = check('min', vertex)
    clearUnion(vertex)
    max_ = check('max', vertex)
    if min_ <= goal <= max_:
        print(1)
    else:
        print(0)
