for _ in range(3):
    zero_count = list(map(int, input().split())).count(0)

    if zero_count == 0:
        print("E")
    elif zero_count == 1:
        print("A")
    elif zero_count == 2:
        print("B")
    elif zero_count == 3:
        print("C")
    else:
        print("D")
