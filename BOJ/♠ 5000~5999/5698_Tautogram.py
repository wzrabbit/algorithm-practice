while True:
    words = input().split()
    success = True

    if words[0] == '*':
        break

    for i in range(len(words) - 1):
        if words[i][0].lower() != words[i + 1][0].lower():
            success = False
            break

    if success:
        print("Y")
    else:
        print("N")
