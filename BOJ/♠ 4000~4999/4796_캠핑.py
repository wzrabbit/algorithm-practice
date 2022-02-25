import sys
input = sys.stdin.readline
no = 1

while True:
    l, u, a = list(map(int, input().split(' ')))
    if l + u + a == 0:
        break
    result = l * (a // u) + min(l, a % u)
    print("Case {0}: {1}".format(no, result))
    no += 1
