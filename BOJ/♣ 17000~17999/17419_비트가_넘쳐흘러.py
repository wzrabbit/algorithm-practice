n = int(input())
t = input()
c = 0

for i in range(n):
    if t[i] == '1':
        c += 1

print(c)
