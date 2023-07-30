N = int(input())
mice = []


def get_smallest_square(cur_time):
    min_x = 1e7
    min_y = 1e7
    max_x = -1e7
    max_y = -1e7

    for i in range(N):
        min_x = min(min_x, mice[i][0] + cur_time * mice[i][2])
        min_y = min(min_y, mice[i][1] + cur_time * mice[i][3])
        max_x = max(max_x, mice[i][0] + cur_time * mice[i][2])
        max_y = max(max_y, mice[i][1] + cur_time * mice[i][3])

    result = max(max_x - min_x, max_y - min_y)
    return result


for _ in range(N):
    mice.append(list(map(float, input().split())))

start = 0.0
end = 2000.0

for i in range(1234):
    p = start + (end - start) / 3
    q = start + (end - start) / 3 * 2

    if get_smallest_square(p) >= get_smallest_square(q):
        start = p
    else:
        end = q

answer = get_smallest_square(start)
print(f"{answer:.10f}")
