a = list(map(int, input().split()))
b = list(map(int, input().split()))
win = 0
all = 36

for i in range(6):
    for j in range(6):
        if a[i] > b[j]:
            win += 1

while win % 2 == 0 and all % 2 == 0:
    win //= 2
    all //= 2

while win % 3 == 0 and all % 3 == 0:
    win //= 3
    all //= 3

print('{}/{}'.format(win, all))
