monster, ignore = map(int, input().split())
defend = monster * (100 - ignore)

if defend < 10000:
    print(1)
else:
    print(0)
