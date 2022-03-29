a = {'A': 4, 'B': 3, 'C': 2, 'D': 1}
b = {'+': 0.3, '0': 0.0, '-': -0.3}

i = input()
if i == 'F':
    print(0.0)
else:
    print(a[i[0]] + b[i[1]])