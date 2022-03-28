import sys
input = sys.stdin.readline
word = input().strip()

word = word.replace('B', 'v')
word = word.replace('E', 'ye')
word = word.replace('H', 'n')
word = word.replace('P', 'r')
word = word.replace('C', 's')
word = word.replace('Y', 'u')
word = word.replace('X', 'h')
word = word.lower()

print(word)
