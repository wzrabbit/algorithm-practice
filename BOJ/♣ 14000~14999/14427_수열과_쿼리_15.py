import sys


def compare(x, y):
    if raw[x] < raw[y]:
        return x
    elif raw[x] > raw[y]:
        return y
    else:
        return min(x, y)


def make_seg_tree(start, end, idx):
    if start == end:
        seg_tree[idx] = start
        return start

    mid = (start + end) // 2
    x = make_seg_tree(start, mid, idx * 2 + 1)
    y = make_seg_tree(mid + 1, end, idx * 2 + 2)
    seg_tree[idx] = compare(x, y)
    return seg_tree[idx]


def get_min_index(start, end, idx, left, right):
    if left > end or right < start:
        return n
    if left <= start and right >= end:
        return seg_tree[idx]

    mid = (start + end) // 2
    x = get_min_index(start, mid, idx * 2 + 1, left, right)
    y = get_min_index(mid + 1, end, idx * 2 + 2, left, right)
    best = compare(x, y)
    return best


def update_value(start, end, idx, target):
    if target < start or target > end:
        return seg_tree[idx]
    if target == start == end:
        return target

    mid = (start + end) // 2
    x = update_value(start, mid, idx * 2 + 1, target)
    y = update_value(mid + 1, end, idx * 2 + 2, target)
    seg_tree[idx] = compare(x, y)
    return seg_tree[idx]


input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
raw = list(map(int, input().split()))
raw.append(1e9 + 1)
seg_tree = [n] * ((n + 1) * 4)
make_seg_tree(0, n, 0)

query = int(input())
for _ in range(query):
    command = list(map(int, input().split()))

    if command[0] == 1:
        _, a, b = command
        a -= 1
        raw[a] = b
        update_value(0, n, 0, a)
    else:
        result = get_min_index(0, n, 0, 0, n) + 1
        print(str(result) + '\n')
