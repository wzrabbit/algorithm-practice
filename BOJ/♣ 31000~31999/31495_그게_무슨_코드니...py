S = input()
success = True

if len(S) <= 2:
    print("CE")
    exit()

for i in range(len(S)):
    if (i == 0 or i == len(S) - 1) and S[i] != '"':
        print("CE")
        exit()

    if i != 0 and i != len(S) - 1 and S[i] == '"':
        print("CE")
        exit()

print(S[1:-1])
