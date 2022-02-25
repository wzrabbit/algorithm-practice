changer = {
    'black': 0, 'brown': 1, 'red': 2, 'orange': 3, 'yellow': 4,
    'green': 5, 'blue': 6, 'violet': 7, 'grey': 8, 'white': 9
}

data = []
for i in range(3):
    data.append(changer[input()])

print((data[0] * 10 + data[1]) * (10 ** data[2]))
