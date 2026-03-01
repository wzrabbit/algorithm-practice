Q = int(input())
problems = 0

for _ in range(Q):
    a, b = map(int, input().split())

    if a == 1:
        problems += b
    else:
        problems -= b

    if problems < 0:
        print('Adios')
        exit()

print('See you next month')
