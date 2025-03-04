N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

max_combo = 0
newer_team = None
last_win_team = None
combo = 0

for i in range(N):
    is_A_win = (A[i], B[i]) in ((2, 1), (3, 2), (1, 3)) or (A[i] == B[i] and newer_team != "B")

    if last_win_team != "B" and is_A_win:
        combo += 1
    elif last_win_team != "A" and not is_A_win:
        combo += 1
    else:
        combo = 1

    if is_A_win:
        newer_team = "B"
        last_win_team = "A"
    else:
        newer_team = "A"
        last_win_team = "B"

    max_combo = max(max_combo, combo)

print(max_combo)
