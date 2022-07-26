X, Y = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())

if x1 == x2:
    case = (
        (x1 - 1, min(y1, y2) - 1),
        (x1 - 1, max(y1, y2) + 1),
        (x1 + 1, min(y1, y2) - 1),
        (x1 + 1, max(y1, y2) + 1),
        (x1 - 1, (y1 + y2) // 2),
        (x1 + 1, (y1 + y2) // 2)
    )
    for i in range(6):
        if 0 <= case[i][0] < X and 0 <= case[i][1] < Y:
            print(case[i][0], case[i][1])
            break
elif y1 == y2:
    case = (
        (min(x1, x2) - 1, y1 - 1),
        (max(x1, x2) + 1, y1 - 1),
        (min(x1, x2) - 1, y1 + 1),
        (max(x1, x2) + 1, y1 + 1),
        ((x1 + x2) // 2, y1 - 1),
        ((x1 + x2) // 2, y1 + 1)
    )
    for i in range(6):
        if 0 <= case[i][0] < X and 0 <= case[i][1] < Y:
            print(case[i][0], case[i][1])
            break
elif abs(x1 - x2) > 1:
    print(f'{max(x1, x2) - 1} {max(y1, y2)}')
elif abs(y1 - y2) > 1:
    print(f'{max(x1, x2)} {max(y1, y2) - 1}')
else:
    if x1 > x2:
        x1, x2 = x2, x1
        y1, y2 = y2, y1

    if y1 < y2:
        case = (
            (x1 - 1, y1),
            (x1, y1 - 1),
            (x2 + 1, y2),
            (x2, y2 + 1)
        )
        for i in range(6):
            if 0 <= case[i][0] < X and 0 <= case[i][1] < Y:
                print(case[i][0], case[i][1])
                break
    else:
        case = (
            (x1 - 1, y1),
            (x1, y1 + 1),
            (x2 + 1, y2),
            (x2, y2 - 1)
        )
        for i in range(6):
            if 0 <= case[i][0] < X and 0 <= case[i][1] < Y:
                print(case[i][0], case[i][1])
                break
