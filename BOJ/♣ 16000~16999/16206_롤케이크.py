import sys
slicer = list(map(int, sys.stdin.readline().split(' ')))[1]
cake = list(map(int, sys.stdin.readline().split(' ')))
total = 0
cake.sort()
cake.sort(key=lambda x: x % 10)

for i in cake:
    if i < 10:
        continue
    elif i == 10:
        total += 1
        continue
    elif i % 10 == 0:
        if slicer >= i // 10 - 1:
            slicer -= i // 10 - 1
            total += i // 10
            if slicer == 0:
                break
        else:
            total += slicer
            break
    else:
        if slicer >= i // 10:
            slicer -= i // 10
            total += i // 10
            if slicer == 0:
                break
        else:
            total += slicer
            break

print(total)
