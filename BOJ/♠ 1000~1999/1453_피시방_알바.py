n = int(input())
pc = [0 for i in range(101)]
data = list(map(int, input().split()))
count = 0

for i in range(len(data)):
    if pc[data[i]] == 0:
        pc[data[i]] = 1
    else:
        count += 1

print(count)