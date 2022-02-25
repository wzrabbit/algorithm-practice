import sys
input = sys.stdin.readline
print = sys.stdout.write
case = int(input())

for i in range(case):
    word = list(map(str, input().strip().split(' ')))
    eraseList = []
    while True:
        erase = input().strip()
        if erase == 'what does the fox say?':
            break
        eraseList.append(erase.split(' ')[2])

    for i in range(len(word)):
        if word[i] not in eraseList:
            print(word[i] + ' ')
    print('\n')
