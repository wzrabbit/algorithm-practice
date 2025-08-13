N, M = map(int, input().split())
targets = []
score = 0
cur_x = 0
cur_y = 0

def get_dist(next_pos):
    next_x, next_y = next_pos
    return abs(next_x - cur_x) ** 2 + abs(next_y - cur_y) ** 2

for _ in range(N):
    x, y = map(int, input().split())
    targets.append((x, y))

for i in range(M):
    targets.sort(key=lambda x: get_dist(x))
    score += get_dist(targets[-1])
    cur_x = targets[-1][0]
    cur_y = targets[-1][1]
    targets.pop()
    x, y = map(int, input().split())
    
    # 입력 검증 / M개의 추가 과녁 정보가 주어져야 하고, 범위는 x, y모두 -100 <= ? <= 100
    assert(-100 <= x <= 100 and -100 <= y <= 100)
    targets.append((x, y))

print(score)
