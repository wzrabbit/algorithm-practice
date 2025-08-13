N = int(input())
S = input()

if N % 3 != 0 or S.count("O") != N // 3:
    print("mix")
    exit()

score_left = 0
score_right = 0
success = True

for i in range(N):
    if S[i] == 'O':
        score_left -= 1
    else:
        score_left += 1
    
    if score_left < 0:
        success = False
        break

for i in reversed(range(N)):
    if S[i] == 'O':
        score_right -= 1
    else:
        score_right += 1
    
    if score_right < 0:
        success = False
        break

if success:
    print("pure")
else:
    print("mix")
