arr = list(map(int, input().split()))
order = input()
arr.sort()

for i in range(3):
    print(f'{arr[ord(order[i]) - 65]}', end=' ')
