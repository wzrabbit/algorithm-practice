N, K = map(int, input().split())
S = list(input())

for i in range(N):
    if S[i] == "A":
        continue

    need_spin_count = ord("Z") - ord(S[i]) + 1

    if K >= need_spin_count:
        K -= need_spin_count
        S[i] = "A"

if K > 0:
    K %= 26
    S[-1] = chr((ord(S[-1]) - 65 + K) % 26 + 65)

print("".join(S))
