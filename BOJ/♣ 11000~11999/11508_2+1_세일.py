import sys
cases = int(sys.stdin.readline())
price = []
total = 0
for _ in range(cases):
    price.append(int(sys.stdin.readline()))
price.sort(reverse = True)
for i in range(cases):
    if (i + 1) % 3 != 0:
        total += price[i]
print(total)