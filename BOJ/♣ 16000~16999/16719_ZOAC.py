S = input()
answer = None

for i in range(len(S)):
    cur = [(i, i)]

    for j in range(len(S) - 1):
        start, end = cur[-1]

        if start == 0:
            cur.append((start, end + 1))
            continue

        if end == len(S) - 1:
            cur.append((start - 1, end))
            continue
        
        if S[start - 1 : end + 1] < S[start : end + 2]:
            