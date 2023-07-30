direction = 0
text = ("N", "E", "S", "W")

for i in range(10):
    query = int(input())

    if query == 1:
        direction = (direction + 1) % 4
    elif query == 2:
        direction = (direction + 2) % 4
    else:
        direction = (direction + 3) % 4

print(text[direction])
