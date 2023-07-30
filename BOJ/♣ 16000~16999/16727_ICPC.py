P1, S1 = map(int, input().split())
S2, P2 = map(int, input().split())

P_sum = P1 + P2
S_sum = S1 + S2

if P_sum > S_sum:
    print("Persepolis")
elif P_sum < S_sum:
    print("Esteghlal")
else:
    if P1 > S2:
        print("Esteghlal")
    elif P1 < S2:
        print("Persepolis")
    else:
        print("Penalty")
