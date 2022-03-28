import sys
cases = int(sys.stdin.readline())

for _ in range(cases):
    length = int(sys.stdin.readline())
    before = sys.stdin.readline().strip()
    after = sys.stdin.readline().strip()
    wb = 0
    bw = 0

    for i in range(length):
        if before[i] == 'W' and after[i] == 'B':
            wb += 1
        elif before[i] == 'B' and after[i] == 'W':
            bw += 1

    print(min(wb, bw) + abs(wb - bw))
