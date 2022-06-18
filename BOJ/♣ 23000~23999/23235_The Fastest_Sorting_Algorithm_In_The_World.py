import sys
input = sys.stdin.readline
print = sys.stdout.write

no = 1
while True:
    if input().strip() == '0':
        break

    print(f'Case {no}: Sorting... done!\n')
    no += 1
