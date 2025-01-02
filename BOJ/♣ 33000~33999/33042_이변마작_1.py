N = int(input())
arr = input().split()
db = dict()

for i in range(len(arr)):
    cur = arr[i]

    if cur in db:
        db[cur] += 1
    else:
        db[cur] = 1

    if db[cur] == 5:
        print(i + 1)
        exit()

print(0)
