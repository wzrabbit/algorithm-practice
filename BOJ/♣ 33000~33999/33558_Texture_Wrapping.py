def init():
    for tr in range(TR):
        for tc in range(TC):
            if not (0 <= tr < R and 0 <= tc < C):
                continue

            grid[tr][tc] = texture[tr][tc]

def print_result():
    for r in range(R):
        print("".join(grid[r]))

def clamp_to_edge():
    init()

    if C > TC:
        for r in range(min(R, TR)):
            base = grid[r][TC - 1]

            for c in range(TC, C):
                grid[r][c] = base

    if R > TR:
        for c in range(min(C, TC)):
            base = grid[TR - 1][c]

            for r in range(TR, R):
                grid[r][c] = base

    if C > TC and R > TR:
        base = grid[TR - 1][TC - 1]

        for r in range(TR, R):
            for c in range(TC, C):
                grid[r][c] = base

    print_result()

def repeat():
    init()

    for r in range(R):
        for c in range(C):
            if not 0 <= r < TR:
                grid[r][c] = grid[r - TR][c]
            
            if not 0 <= c < TC:
                grid[r][c] = grid[r][c - TC]

    print_result()

def mirrored_repeat():
    stamp = [["."] * TC * 2 for _ in range(TR * 2)]

    for tr in range(TR):
        for tc in range(TC):
            if not (0 <= tr < R and 0 <= tc < C):
                continue

            stamp[tr][tc] = texture[tr][tc]

    for r in range(TR):
        for c in range(TC):
            stamp[r][-c - 1] = texture[r][c]
            stamp[-r - 1][c] = texture[r][c]
            stamp[-r - 1][-c - 1] = texture[r][c]
    
    for r in range(R):
        for c in range(C):
            grid[r][c] = stamp[r % (TR * 2)][c % (TC * 2)]

    print_result()

R, C = map(int, input().split())
TR, TC = map(int, input().split())
texture = []
grid = [["."] * C for _ in range(R)]

for _ in range(TR):
    texture.append(list(input()))

method = input()

if method == "clamp-to-edge":
    clamp_to_edge()
elif method == "repeat":
    repeat()
else:
    mirrored_repeat()
