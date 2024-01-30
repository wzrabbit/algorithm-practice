S = input()
joi = 0
ioi = 0

for i in range(len(S) - 2):
    cur = S[i : i + 3]

    if cur == "JOI":
        joi += 1
    elif cur == "IOI":
        ioi += 1

print(joi)
print(ioi)
