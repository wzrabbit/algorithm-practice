no = 1

while True:
    data = input()
    if data == '0':
        break

    T, W, H = map(int, data.split())
    if (T * 2) ** 2 >= W ** 2 + H ** 2:
        print(f'Pizza {no} fits on the table.')
    else:
        print(f'Pizza {no} does not fit on the table.')

    no += 1
