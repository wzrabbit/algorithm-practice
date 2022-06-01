import sys
input = sys.stdin.readline
print = sys.stdout.write

n, q = map(int, input().split())
union = [-1] * n
rank = [1] * n
namu = []


def get_parent(child):
    if union[child] == -1:
        return child
    union[child] = get_parent(union[child])
    return union[child]


def merge(a, b):
    a = get_parent(a)
    b = get_parent(b)

    if a != b:
        if rank[a] > rank[b]:
            union[b] = a
            rank[a] += rank[b]
        else:
            union[a] = b
            rank[b] += rank[a]


for i in range(n):
    s, e, _ = map(int, input().split())
    namu.append((s, e, i))
namu.sort(key=lambda x: x[0])

start = namu[0][0]
end = namu[0][1]
for i in range(1, n):
    ps, pe, no = namu[i]
    if ps <= end:
        end = max(end, pe)
        merge(namu[i - 1][2], no)
    else:
        start = ps
        end = pe


for _ in range(q):
    s, e = map(int, input().split())
    s -= 1
    e -= 1

    if get_parent(s) == get_parent(e):
        print('1\n')
    else:
        print('0\n')
