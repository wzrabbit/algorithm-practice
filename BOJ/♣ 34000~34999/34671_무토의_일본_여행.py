import sys
input = sys.stdin.readline

V, E, Q = map(int, input().split())
db = dict()

for _ in range(E):
    s, e, d = map(int, input().split())

    if f'{s},{e}' in db:
        db[f'{s},{e}'] = min(db[f'{s},{e}'], d)
    else:
        db[f'{s},{e}'] = d

    if f'{e},{s}' in db:
        db[f'{e},{s}'] = min(db[f'{e},{s}'], d)
    else:
        db[f'{e},{s}'] = d

for _ in range(Q):
    s, e = map(int, input().split())

    if f'{s},{e}' in db:
        print(db[f'{s},{e}'])
    else:
        print(-1)
