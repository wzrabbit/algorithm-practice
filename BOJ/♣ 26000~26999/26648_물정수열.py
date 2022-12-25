import sys
input = sys.stdin.readline


def get_next_mid(before, val1, val2, val3):
    arr = sorted([val1, val2, val3])
    if before + 1 < arr[0]:
        return arr[0]

    if arr[0] <= before + 1 <= arr[2]:
        return before + 1
    return -1


N = int(input())
is_possible = 'YES'
scores = []
for _ in range(3):
    scores.append(list(map(int, input().split())))

mid = min(scores[0][0], scores[1][0], scores[2][0])

for i in range(1, N):
    nxt = get_next_mid(mid, scores[0][i], scores[1][i], scores[2][i])
    if nxt == -1:
        is_possible = 'NO'
        break
    mid = nxt

print(is_possible)
