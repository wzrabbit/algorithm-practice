import sys
input = sys.stdin.readline
result = {}
data = 0

def backTracking(current, cnt, goal):
    if cnt == goal:
        if '3' in str(current):
            if result.get(current) == None:
                result[current] = 1
            else:
                result[current] += 1
        return

    backTracking(current + data[cnt + 1], cnt + 1, goal)
    backTracking(abs(current - data[cnt + 1]), cnt + 1, goal)
    backTracking(current * data[cnt + 1], cnt + 1, goal)
    if data[cnt + 1] != 0:
        backTracking(current // data[cnt + 1], cnt + 1, goal)

while True:
    data = input().rstrip().split()
    result = {}
    if data[0] == '#':
        break
    else:
        data = list(map(int, data))
    backTracking(data[0], 0, len(data) - 1)
    result = list(result.items())
    max_ = [-1, -1]
    for i in range(len(result)):
        if max_[1] < result[i][1] or (max_[1] == result[i][1] and max_[0] < result[i][0]):
            max_[0] = result[i][0]
            max_[1] = result[i][1]
    if max_[0] == -1:
        print('No result')
    else:
        print(max_[0])