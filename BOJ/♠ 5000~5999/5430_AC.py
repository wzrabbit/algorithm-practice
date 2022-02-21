import sys
import re
from collections import deque
cases = int(sys.stdin.readline())

for i in range(cases):
    command = sys.stdin.readline()
    length = int(sys.stdin.readline())
    data = sys.stdin.readline()
    isReversed = False
    error = False

    data = re.sub('[\[\]\n]', '', data).split(',')
    if data == ['']:
        data = deque([])
    else:
        data = deque(map(int, data))
    command = re.sub('RR|\n', '', command)

    for j in command:
        if j == 'R':
            isReversed = not isReversed
        else:
            if len(data) == 0:
                print('error')
                error = True
                break
            else:
                if isReversed:
                    data.pop()
                else:
                    data.popleft()

    if error == False:
        if isReversed:
            data.reverse()
        result = re.sub(' ', '', str(list(data)))
        print(result)