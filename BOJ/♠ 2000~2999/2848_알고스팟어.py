import sys
from collections import deque
input = sys.stdin.readline

tc = int(input())
priority = [-1 for i in range(26)]
graph = [[] for i in range(26)]
word = []
result = ':)'

for t in range(tc):
    current = input().rstrip()
    word.append(current)
    spect = list(current)
    for i in spect:
        priority[ord(i) - 97] = 0

kill = False
for i in range(tc):
    if kill == True:
        break
    for j in range(i + 1, tc):
        check = min(len(word[i]), len(word[j]))
        changed = False
        for k in range(check):
            if word[i][k] == word[j][k]:
                continue
            else:
                changed = True
                l = ord(word[i][k]) - 97
                r = ord(word[j][k]) - 97

                if r not in graph[l]:
                    graph[l].append(r)
                    priority[r] += 1
                break
        if changed == False and len(word[i]) > len(word[j]):
            result = '!'
            kill = True

queue = deque()
count = 0
expectedCount = 0
order = ''
for i in range(26):
    if priority[i] == 0:
        queue.append(i)
        count += 1
    if priority[i] != -1:
        expectedCount += 1
if count == 0:
    result = '!'
elif count >= 2 and result == ':)':
    result = '?'

count = 0
if result == ':)':
    while queue:
        count += 1
        added = 0
        current = queue.popleft()
        order += chr(current + 97)
        for i in graph[current]:
            priority[i] -= 1
            if priority[i] == 0:
                queue.append(i)
                added += 1
        if added >= 2:
            result = '?'

    if count < expectedCount:
        result = '!'

if result == ':)':
    print(order)
else:
    print(result)
