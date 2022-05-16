import sys
input = sys.stdin.readline

n = int(input())
gom = 0
db = {}

for i in range(n):
    text = input().strip()
    if text == 'ENTER':
        db = {}
    else:
        if text not in db:
            gom += 1
            db[text] = 1

print(gom)
