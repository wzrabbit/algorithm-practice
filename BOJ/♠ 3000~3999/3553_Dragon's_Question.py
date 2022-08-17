length, num = input().split()
length = int(length)

if len(num) <= length:
    print(num.ljust(length, '0'))
else:
    print('No solution')
