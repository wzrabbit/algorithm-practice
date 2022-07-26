class Dice:
    def __init__(self):
        self.r = [2, 1, 5]
        self.c = [3, 1, 4, 6]

    def roll_up(self):
        self.r[0], self.r[1], self.r[2], self.c[3] = self.r[1], self.r[2], self.c[3], self.r[0]
        self.c[1] = self.r[1]

    def roll_down(self):
        self.r[0], self.r[1], self.r[2], self.c[3] = self.c[3], self.r[0], self.r[1], self.r[2]
        self.c[1] = self.r[1]

    def roll_left(self):
        self.c.append(self.c.pop(0))
        self.r[1] = self.c[1]

    def roll_right(self):
        self.c.insert(0, self.c.pop())
        self.r[1] = self.c[1]

    def get_value(self):
        return self.r[1]


while True:
    dice = Dice()
    N = int(input())
    if N == 0:
        break

    for _ in range(N):
        com = input()

        if com == 'north':
            dice.roll_up()
        elif com == 'south':
            dice.roll_down()
        elif com == 'west':
            dice.roll_left()
        else:
            dice.roll_right()

    print(dice.get_value())
