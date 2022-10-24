T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    comb = input()
    if len(comb) >= 1 and comb[0] == '1':
        print(N, K - 1)
        print(comb[2:])
    else:
        print(N, K + 1)
        print('1 ' + comb)
