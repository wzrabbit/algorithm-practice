import sys
from collections import deque
ladder, snake = map(int, sys.stdin.readline().split())
game = [0 for i in range(101)]
visited = [False for i in range(101)]
visited[1] = True


def bfs():
    q = deque([[1, 0]])

    while len(q):
        l, d = q.popleft()

        if l == 100:
            print(d)
            return

        for j in range(1, 7):
            nextD = l + j
            if nextD <= 100 and visited[nextD] == False:
                visited[nextD] = True

                if game[nextD] != 0:
                    while game[nextD] != 0:
                        nextD = game[nextD]
                        visited[nextD] = True

                q.append([nextD, d + 1])


for i in range(ladder):
    before, after = map(int, sys.stdin.readline().split())
    game[before] = after

for i in range(snake):
    before, after = map(int, sys.stdin.readline().split())
    game[before] = after

bfs()
