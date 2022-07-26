import sys
input = sys.stdin.readline

N = int(input())
answer = {'no': 0, 'min': 100000}

for i in range(1, N + 1):
    a, b = map(int, input().split())
    calc = ((a - 1) // (b + 1) + 1) * 2

    if calc < answer['min']:
        answer['no'] = i
        answer['min'] = calc

print(answer['no'], answer['min'])
