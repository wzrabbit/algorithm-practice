T = int(input())

for _ in range(T):
    S = input().lower()
    missing = []

    for i in range(26):
        cur = chr(97 + i)

        if cur not in S:
            missing.append(cur)

    if len(missing) == 0:
        print("pangram")
    else:
        print("missing", "".join(missing))
