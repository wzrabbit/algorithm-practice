R, C = map(int, input().split())
game = []

for _ in range(R):
    game.append(sum(list(map(int, input().split()))))

result = game[0]
for i in range(1, R):
    result ^= game[i]

if result == 0:
    print('ainta')
else:
    print('august14')
