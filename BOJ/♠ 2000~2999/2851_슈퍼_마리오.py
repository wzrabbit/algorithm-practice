best = {'score': 0, 'gap': 100}
cur = 0

for i in range(10):
    cur += int(input())
    if abs(cur - 100) <= best['gap']:
        best['score'] = cur
        best['gap'] = abs(cur - 100)

print(best['score'])
