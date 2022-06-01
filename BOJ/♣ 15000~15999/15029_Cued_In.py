n = int(input())
db = {'red': 1, 'yellow': 2, 'green': 3, 'brown': 4,
      'blue': 5, 'pink': 6, 'black': 7}
repeat = 0
sum_ball = 0
max_ball = 0

for i in range(n):
    current = input()
    if db[current] == 1:
        repeat += 1
    else:
        max_ball = max(max_ball, db[current])
        sum_ball += db[current]

if sum_ball == 0:
    print(1)
else:
    print(max_ball * repeat + repeat + sum_ball)
