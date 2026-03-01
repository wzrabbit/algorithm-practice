N = int(input())
rules = dict()

for _ in range(N):
    data = input().split()
    rules[data[0]] = data[2:]

S = input()

for i in range(len(S) - 1):
    if S[i] in rules and S[i + 1] not in rules[S[i]]:
        print('no')
        exit()

print('yes')
