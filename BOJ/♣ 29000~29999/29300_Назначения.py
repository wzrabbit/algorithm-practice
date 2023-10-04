S = input()
selected_char = None
for i in range(len(S) - 1):
    if S[i] > S[i + 1]:
        selected_char = S[i]
        break

if selected_char == None:
    selected_char = S[-1]

print(S.replace(selected_char, ""))
