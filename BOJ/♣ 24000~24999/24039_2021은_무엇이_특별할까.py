e = [1 for i in range(20001)]
f = []
g = []
e[1] = 0

q = int(input())

for i in range(2, 500):
    if e[i] == 1:
        j = i * 2
        while j <= 20000:
            e[j] = 0
            j += i

for i in range(2, 20001):
    if e[i] == 1:
        f.append(i)

for i in range(len(f) - 1):
    g.append(f[i] * f[i + 1])

for i in range(len(g)):
    if q < g[i]:
        print(g[i])
        break
