import sys
print = sys.stdout.write


while True:
    try:
        n = int(input())
    except EOFError:
        break

    text = '-'

    for _ in range(n):
        text = text + ' ' * len(text) + text

    print(text + '\n')
