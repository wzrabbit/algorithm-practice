num = int(input())

inf = 300001
dpA = [1]
dpB = [1]
dpC = [inf for i in range(num + 1)]
dpC[0] = 0
dpC[1] = 1

i = 2
while True:
    c = dpA[i - 2] + i
    if c > num:
        break
    dpA.append(c)
    i += 1

for i in range(len(dpA) - 1):
    dpB.append(dpB[i] + dpA[i + 1])

for i in range(1, len(dpC)):
    for j in range(len(dpB)):
        if i - dpB[j] >= 0:
            dpC[i] = min(dpC[i], dpC[i - dpB[j]] + 1)

print(dpC[num])