ball_dist = 50 - list(map(int, input().split()))[0]
off_dist = []
def_dist = []

for _ in range(11):
    off_dist.append(50 - list(map(int, input().split()))[0])

for _ in range(11):
    def_dist.append(50 - list(map(int, input().split()))[0])

off_dist.sort()
def_dist.sort()

if off_dist[0] < 50 and off_dist[0] < ball_dist and off_dist[0] < def_dist[1]:
    print(1)
else:
    print(0)
