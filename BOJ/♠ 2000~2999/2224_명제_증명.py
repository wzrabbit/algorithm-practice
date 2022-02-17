import sys
input = sys.stdin.readline
prop = int(input())
graph = [[0 for j in range(52)] for i in range(52)]

for i in range(prop):
    s, e = list(map(str, input().strip().split(' => ')))
    if ord(s) >= 97:
        s = ord(s) - 71
    else:
        s = ord(s) - 65
    if ord(e) >= 97:
        e = ord(e) - 71
    else:
        e = ord(e) - 65
    graph[s][e] = 1

for m in range(52):
    for s in range(52):
        for e in range(52):
            if s != e and graph[s][m] + graph[m][e] == 2:
                graph[s][e] = 1

result = ''
count = 0
for i in range(52):
    for j in range(52):
        if i != j and graph[i][j] == 1:
            x, y = i, j
            if x >= 26:
                x = chr(x + 71)
            else:
                x = chr(x + 65)
            if y >= 26:
                y = chr(y + 71)
            else:
                y = chr(y + 65)
            result += x + ' => ' + y + '\n'
            count += 1

print(count)
print(result)