T = int(input())

for _ in range(T):
    expression = input().replace('/', '//')
    print(eval(expression))
