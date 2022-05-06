import sys
input = sys.stdin.readline

n, k = map(int, input().split())
basket = list(map(int, input().split()))
stealed = 0
day = 0

for i in range(1, n):
    if basket[i] > basket[0]:
        day += 1
    stealed += basket[i] - basket[0]

print(stealed, day)
