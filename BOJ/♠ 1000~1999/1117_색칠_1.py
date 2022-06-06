width, height, fold_right, fold_down, x1, y1, x2, y2 = map(
    int, input().split())
result = width * height

result -= (fold_down + 1) * (y2 - y1) * (x2 - x1)

if fold_right <= width - fold_right:
    result -= (fold_down + 1) * (y2 - y1) * max(0, (min(x2, fold_right) - x1))
else:
    result -= (fold_down + 1) * (y2 - y1) * \
        max(0, (min(x2, width - fold_right) - x1))

print(result)
