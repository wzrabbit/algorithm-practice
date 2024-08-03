A = list(map(int, input().split()))
B = list(map(int, input().split()))
A_score = 0
B_score = 0
last_win_player = 'D'

for i in range(10):
    if A[i] > B[i]:
        A_score += 3
        last_win_player = 'A'
    elif A[i] < B[i]:
        B_score += 3
        last_win_player = 'B'
    else:
        A_score += 1
        B_score += 1

print(A_score, B_score)

if A_score > B_score:
    print('A')
elif A_score < B_score:
    print('B')
else:
    print(last_win_player)
