N = int(input())

for i in reversed(range(1, N + 1)):
    if str(i).replace('4', '').replace('7', '') == '':
        print(i)
        break
