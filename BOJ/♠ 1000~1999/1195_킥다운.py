S = list(map(int, list(input())))
T = list(map(int, list(input())))

if len(S) < len(T):
    S, T = T, S

init_len = len(S)

S = [0] * len(T) + S + [0] * len(T)
best = 999999

for i in range(len(S) - len(T) + 1):
    cur = init_len
    success = True

    for j in range(i, i + len(T)):
        if S[j] + T[j - i] == 4:
            success = False
            break

        if S[j] == 0 or T[j - i] == 0:
            cur += 1

    if success:
        best = min(best, cur)

print(best)
