numbers = set()

for i in range(2, 10):
    for j in range(1, 10):
        numbers.add(i * j)
        numbers.add(i)
        numbers.add(j)

N = int(input())

if N in numbers:
    print(1)
else:
    print(0)
