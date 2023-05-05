N = int(input())

for _ in range(N):
    S, T = input().split()
    gap = len(S) - len(T)

    if gap == 0:
        if S == T:
            print('Alice')
        else:
            print('Bob')
    elif gap % 2 == 0:
        l = gap // 2
        r = len(S) - gap // 2

        if S[l:r] == T:
            print('Alice')
        elif S[l - 1: r - 1] == T and S[l + 1: r + 1] == T:
            print('Alice')
        else:
            print('Bob')
    else:
        l = gap // 2
        r = len(S) - gap // 2

        if S[l + 1: r] == T and S[l: r - 1] == T:
            print('Alice')
        else:
            print('Bob')
