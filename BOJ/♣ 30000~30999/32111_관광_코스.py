N = int(input())
S = input()

if S.count("X") == N:
    print("YES")
    print("-" * N)
    exit()

answer = ["-"] * N

start_index = S.index("O")
X_combo = 0
success = True

for i in range(N + 1):
    prev = (start_index - 1 + i + N) % N
    cur = (start_index + i) % N

    if S[cur] == "X":
        X_combo += 1
        continue

    answer[cur] = "+"

    if S[prev] == "X":
        X_start_index = (cur - X_combo + N) % N

        if X_combo % 2 == 0 and X_combo >= 1:
            print("NO")
            exit()

        for j in range(X_combo // 2):
            X_cur = (X_start_index + j) % N
            answer[X_cur] = "+"

        X_combo = 0

print("YES")
print(*answer, sep="")
