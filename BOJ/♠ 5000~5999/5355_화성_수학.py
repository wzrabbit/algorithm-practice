n = int(input())
for _ in range(n):
    opr = input().split()
    result = float(opr[0])

    for i in range(1, len(opr)):
        if opr[i] == '@':
            result *= 3
        elif opr[i] == '%':
            result += 5
        else:
            result -= 7

    print('{:.2f}'.format(result))
