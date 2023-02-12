import sys
input = sys.stdin.readline

N = int(input())
bracket = input().strip()
max_abs = 0
cur_abs = 0

for i in range(N):
    if bracket[i] == '(':
        cur_abs += 1
    else:
        cur_abs -= 1

    max_abs = max(max_abs, abs(cur_abs))

if bracket == '()()':
    print(0)
elif cur_abs != 0 or bracket.find('()()') == -1:
    print(-1)
else:
    print(max_abs)
