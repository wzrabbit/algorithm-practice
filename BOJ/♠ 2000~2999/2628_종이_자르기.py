width, height = map(int, input().split())
cut = int(input())

width_cut = [0, width]
height_cut = [0, height]
max_width = 0
max_height = 0

for i in range(cut):
    query, pos = map(int, input().split())

    if query == 1:
        width_cut.append(pos)
    else:
        height_cut.append(pos)

width_cut.sort()
height_cut.sort()

for i in range(len(width_cut) - 1):
    max_width = max(max_width, width_cut[i + 1] - width_cut[i])

for i in range(len(height_cut) - 1):
    max_height = max(max_height, height_cut[i + 1] - height_cut[i])

print(max_width * max_height)
