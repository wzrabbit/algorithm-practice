T = int(input())


for _ in range(T):
    S = input()
    flipped = False
    num = None

    for i in range(len(S)):
        if S[i] == "1":
            num = 1
            break

        if S[i] == "0":
            if i != len(S) - 1:
                num = 1
            else:
                num = 0
            break

    for i in range(len(S)):
        if S[i] != "!":
            break

        flipped = not flipped

    if flipped:
        num = 1 - num

    print(num)
