import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())
for _ in range(T):
    string = input().rstrip()
    N = len(string)
    prev = ''
    db = {'w': -1, 'b': -1}

    for i in range(N):
        if string[i] != prev:
            prev = string[i]
            db[string[i]] += 1

    if string[0] == string[-1]:
        db[string[0]] -= 1

    ans = min(db['w'], db['b'])
    print(f'{ans}\n')
