N, K = map(int, input().split())
S = input()
boxes = ([], [], [])
colors = "srp"

for cur in S:
    index = colors.index(cur)

    while True:
        if len(boxes[index]) >= K:
            index = (index + 1) % 3
            continue

        boxes[index].append(cur)
        break

for i in range(3):
    print("".join(boxes[i]))
