import sys
l, r = list(map(str, sys.stdin.readline().strip().split(' ')))
eight = 0

if (len(l) != len(r)):
    print(0)
else:
    for i in range(len(l)):
        if l[i] == '8' and r[i] == '8':
            eight += 1
        elif l[i] != r[i]:
            break
    print(eight)
