S = input()
N = len(S)
answer = 0

if S[0] == "0":
    print(0)
    exit()

if N % 2 == 0:
    if int(S[: (N // 2)]) <= int(S[(N // 2) :]):
        answer += 1

for i in range(1, (N + 1) // 2):
    if S[i] != "0":
        answer += 1

print(answer)
