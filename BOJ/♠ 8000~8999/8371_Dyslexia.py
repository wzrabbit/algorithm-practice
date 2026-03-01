N = int(input())
S = input()
T = input()
diff_count = 0

for i in range(N):
    if S[i] != T[i]:
        diff_count += 1

print(diff_count)
