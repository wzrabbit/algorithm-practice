N = int(input())
score_A, score_B = 100, 100

for _ in range(N):
    dice_A, dice_B = map(int, input().split())
    if dice_A > dice_B:
        score_B -= dice_A
    elif dice_A < dice_B:
        score_A -= dice_B

print(score_A)
print(score_B)
