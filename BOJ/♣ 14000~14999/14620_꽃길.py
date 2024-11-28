def get_cost(r1, c1, r2, c2, r3, c3):
    total = 0
    points = ((r1, c1), (r2, c2), (r3, c3))
    used_points = set()

    for i in range(5):
        for j in range(3):
            r = points[j][0] + dr[i]
            c = points[j][1] + dc[i]

            if (r, c) in used_points:
                return -1
            
            total += cost[r][c]
            used_points.add((r, c))
    
    return total

N = int(input())
cost = []
answer = 20001
dr = (0, -1, 1, 0, 0)
dc = (0, 0, 0, -1, 1)

for _ in range(N):
    cost.append(list(map(int, input().split())))

for r1 in range(1, N - 1):
    for c1 in range(1, N - 1):
        for r2 in range(1, N - 1):
            for c2 in range(1, N - 1):
                for r3 in range(1, N - 1):
                    for c3 in range(1, N - 1):
                        cur_cost = get_cost(r1, c1, r2, c2, r3, c3)
                        
                        if cur_cost != -1:
                            answer = min(answer, cur_cost)

print(answer)
