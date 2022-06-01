import sys
print = sys.stdout.write

answer = []
n = int(input())

while n >= 1:
    m = 2
    while m <= n:
        m *= 2
    x = m - n
    for i in range(x, n + 1):
        answer.append(i)
    n = x - 1

for i in reversed(range(len(answer))):
    print(str(answer[i]) + '\n')
