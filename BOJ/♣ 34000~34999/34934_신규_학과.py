N = int(input())

for _ in range(N):
    S = input()
    if S[-4:] == '2026':
        print(S[:-5])
        break
