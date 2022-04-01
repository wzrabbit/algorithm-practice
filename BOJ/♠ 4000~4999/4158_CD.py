import sys
input = sys.stdin.readline
print = sys.stdout.write

while True:
    a, b = list(map(int, input().split()))
    if a == 0 and b == 0:
        break

    cd_set = set()
    count = 0

    for _ in range(a):
        cd_set.add(int(input()))

    for _ in range(b):
        if (int(input()) in cd_set):
            count += 1

    print(str(count) + '\n')
