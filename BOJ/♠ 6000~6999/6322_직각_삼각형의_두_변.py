test_no = 1

while True:
    a, b, c = map(int, input().split())

    if a == 0:
        break

    print(f'Triangle #{test_no}')

    calc = None
    missing_letter = 'a'

    if a == -1:
        calc = c ** 2 - b ** 2
    elif b == -1:
        calc = c ** 2 - a ** 2
        missing_letter = 'b'
    else:
        calc = a ** 2 + b ** 2
        missing_letter = 'c'
    
    if calc > 0:
        print(f'{missing_letter} = {calc ** 0.5:.3f}')
    else:
        print('Impossible.')

    print()
    test_no += 1
