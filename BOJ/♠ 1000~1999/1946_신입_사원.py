import sys
input = sys.stdin.readline
n = int(input())

for _ in range(n):
    arr = []
    employee = int(input())
    for _ in range(employee):
        arr.append(list(map(int, input().split())))
    arr.sort(key = lambda x: x[0])
    
    count = 1
    prev = arr[0][1]
    for i in range(1, employee):
        if arr[i][1] < prev:
            count += 1
            prev = arr[i][1]
    print(count)