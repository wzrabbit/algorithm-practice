S = input()
occur = [0] * 26
odd = True
even = True

for i in range(len(S)):
    occur[ord(S[i]) - 97] += 1

for i in range(26):
    if occur[i] == 0:
        continue

    if occur[i] % 2 == 0:
        odd = False
    else:
        even = False

if even:
    print(0)
elif odd:
    print(1)
else:
    print(2)
