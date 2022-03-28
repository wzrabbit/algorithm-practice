import sys
input = sys.stdin.readline
row, col, sticker = list(map(int, input().split()))
laptop = [[0 for j in range(col)] for i in range(row)]
stickers = []
count = 0

for i in range(sticker):
    stickers.append([])
    r, _ = list(map(int, input().split()))
    for j in range(r):
        stickers[i].append(list(map(int, input().split())))


def rotate(index):
    data = stickers[index]
    row = len(data)
    col = len(data[0])
    newSticker = [[0 for j in range(row)] for i in range(col)]
    for r in range(row):
        for c in range(col):
            newSticker[c][row - 1 - r] = data[r][c]
    stickers[index] = newSticker


def stick(index):
    global row
    global col
    stickerRow = len(stickers[index])
    stickerCol = len(stickers[index][0])
    for r in range(row - stickerRow + 1):
        for c in range(col - stickerCol + 1):
            kill = False
            for i in range(r, r + stickerRow):
                for j in range(c, c + stickerCol):
                    if stickers[index][i - r][j - c] == 1 and laptop[i][j] == 1:
                        kill = True
                        break
                if kill:
                    break
            if kill == False:
                for i in range(r, r + stickerRow):
                    for j in range(c, c + stickerCol):
                        if stickers[index][i - r][j - c] == 1 and laptop[i][j] == 0:
                            laptop[i][j] = 1
                return True
    return False


for i in range(len(stickers)):
    for j in range(4):
        if stick(i):
            break
        else:
            rotate(i)

for r in range(row):
    for c in range(col):
        if laptop[r][c] == 1:
            count += 1
print(count)
