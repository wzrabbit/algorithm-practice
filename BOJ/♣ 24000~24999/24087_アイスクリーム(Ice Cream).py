S = int(input())
A = int(input())
B = int(input())
height = 0
cost = 0

height += A
cost += 250

while height < S:
    height += B
    cost += 100

print(cost)
