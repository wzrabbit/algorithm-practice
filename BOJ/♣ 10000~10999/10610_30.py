import sys
input = sys.stdin.readline

text = list(map(int, list(input().strip())))
if 0 in text and sum(text) % 3 == 0:
    print(''.join(map(str, sorted(text, key=lambda x: -x))))
else:
    print(-1)
