import sys
input = sys.stdin.readline
INF = 9999999

data = []

R, C = map(int, input().split())
N = int(input())

for i in range(N + 1):
    data.append({ "start_r": INF, "start_c": INF, "end_r": -INF, "end_c": -INF })

for i in range(N):
    no, r, c = map(int, input().split())
    data[no]["start_r"] = min(data[no]["start_r"], r)
    data[no]["start_c"] = min(data[no]["start_c"], c)
    data[no]["end_r"] = max(data[no]["end_r"], r)
    data[no]["end_c"] = max(data[no]["end_c"], c)

answer = -1
area = 0

for i in range(1, N + 1):
    if data[i]["start_r"] == INF:
        continue

    cur_r_size = data[i]["end_r"] - data[i]["start_r"] + 1
    cur_c_size = data[i]["end_c"] - data[i]["start_c"] + 1
    cur_area = cur_r_size * cur_c_size

    if cur_area > area:
        area = cur_area
        answer = i

print(answer, area)
