while True:
    S = input()
    N = len(S)

    if S == "0":
        break

    answer = 0

    while True:
        if S == S[::-1]:
            print(answer)
            break

        S = str(int(S) + 1).zfill(N)
        answer += 1
