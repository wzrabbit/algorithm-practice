path = [[1, 3], [6, 8], [2, 5]]
success = True

for i in range(3):
    cur = int(input())
    if not cur in path[i]:
        success = False
        break

print('JAH' if success else 'EI')
