import sys
import re
x, y = list(map(int, sys.stdin.readline().split(' ')))
total = x + y
a = list(map(int, sys.stdin.readline().split(' ')))
b = list(map(int, sys.stdin.readline().split(' ')))
a.append(99999999999)
b.append(99999999999)
aIndex = 0
bIndex = 0
a.sort()
b.sort()
answer = []

for i in range(total):
    if a[aIndex] >= b[bIndex]:
        answer.append(b[bIndex])
        bIndex += 1
    else:
        answer.append(a[aIndex])
        aIndex += 1

print(re.sub('[\[\]]', '', ' '.join(list(map(str, answer)))))
