N = int(input())
heart = [
    ' @@@   @@@  ',
    '@   @ @   @ ',
    '@    @    @ ',
    '@         @ ',
    ' @       @  ',
    '  @     @   ',
    '   @   @    ',
    '    @ @     ',
    '     @      '
]

for line in heart:
    print(line * N)
