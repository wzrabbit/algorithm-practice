import sys
input = sys.stdin.readline
print_ = sys.stdout.write

n = int(input())
data = []
power = [7, 7, 7]
before_res = [1, 1, 1]
res = [0, 0, 0]
idx = 0
day = 1
cnt = 0


def get_res():
    max_ = max(power)
    for i in range(3):
        if power[i] == max_:
            res[i] = 1
        else:
            res[i] = 0
    if before_res == res:
        return False
    else:
        return True


for _ in range(n):
    a, b, c = input().split()
    a = int(a)
    c = int(c)
    if b == 'Mildred':
        b = 0
    elif b == 'Elsie':
        b = 1
    else:
        b = 2
    data.append([a, b, c])

data.sort(key=lambda x: x[0])

while day <= 100:
    if idx < n and data[idx][0] == day:
        power[data[idx][1]] += data[idx][2]
        idx += 1
    else:
        if get_res():
            cnt += 1
        before_res = res[:]
        day += 1

print(cnt)
