d, h, w = map(int, input().split(' '))
calc = d / ((h ** 2 + w ** 2) ** 0.5)

print(str(int(calc * h)) + ' ' + str(int(calc * w)))