T = int(input())

for _ in range(T):
    S = input()

    if "MOO" in S:
        print(len(S) - 3)
    elif "OOO" in S or "MOM" in S:
        print(len(S) - 2)
    elif "OOM" in S:
        print(len(S) - 1)
    else:
        print(-1)
