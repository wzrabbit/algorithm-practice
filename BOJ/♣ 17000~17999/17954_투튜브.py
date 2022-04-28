import sys
print = sys.stdout.write

n = int(input())

if n == 1:
    print('2\n1\n2')
    sys.exit()

karma = 0
mul = 1
rot = 0
for i in range(1, n * 2 + 1):
    karma += i

arr = [[0 for i in range(n)] for i in range(2)]

arr[0][0] = 2 * n - 3
arr[0][-1] = 2 * n - 2
arr[1][0] = 2 * n - 1
arr[1][-1] = 2 * n

for i in range(1, n - 1):
    arr[0][i] = 2 * n - 3 - i
    arr[1][i] = arr[0][i] - (n - 2)

for i in range(2):
    for j in range(n):
        karma -= arr[i][j]
        rot += karma * mul
        mul += 1

print(str(rot) + '\n')
for i in range(2):
    for j in range(n):
        print(str(arr[i][j]) + ' ')
    print('\n')
