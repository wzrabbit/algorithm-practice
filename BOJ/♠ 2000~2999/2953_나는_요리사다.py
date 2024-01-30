winner_no = 0
winner_score = 0

for i in range(1, 6):
    cur_score = sum(list(map(int, input().split())))

    if cur_score > winner_score:
        winner_no = i
        winner_score = cur_score

print(winner_no, winner_score)
