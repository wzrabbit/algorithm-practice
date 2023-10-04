import sys

input = sys.stdin.readline
print = sys.stdout.write

S = input()
change_set = set(input().split())

for i in range(len(S)):
    if S[i] in change_set:
        print(S[i].lower())
    else:
        print(S[i])
