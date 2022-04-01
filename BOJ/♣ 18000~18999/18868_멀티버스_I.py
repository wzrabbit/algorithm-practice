import sys
input = sys.stdin.readline

space, planet = list(map(int, input().split()))
slot = []

for i in range(space):
    slot.append(list(map(int, input().split())))


def check(a, b):
    for i in range(planet):
        for j in range(i + 1, planet):
            if slot[a][i] < slot[a][j]:
                if not slot[b][i] < slot[b][j]:
                    return False
            elif slot[a][i] == slot[a][j]:
                if not slot[b][i] == slot[b][j]:
                    return False
            elif slot[a][i] > slot[a][j]:
                if not slot[b][i] > slot[b][j]:
                    return False
    return True


cnt = 0
for i in range(space):
    for j in range(i + 1, space):
        if check(i, j):
            cnt += 1

print(cnt)
