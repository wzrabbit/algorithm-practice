import sys
input = sys.stdin.readline

db = {'II': 0, 'NN': 0, 'UU': 0, 'IN': 0, 'IU': 0, 'NU': 0}
n = int(input())
for _ in range(n):
    stick, length = input().strip().split()
    length = int(length)

    if stick == 'NI':
        stick = 'IN'
    elif stick == 'UI':
        stick = 'IU'
    elif stick == 'UN':
        stick = 'NU'

    db[stick] += length

if db['IN'] == 0 and db['IU'] == 0 and db['NU'] == 0:
    print(max(db['II'], db['NN'], db['UU']))
elif db['IN'] > 0 and db['IU'] == 0 and db['NU'] == 0:
    print(max(db['II'] + db['NN'] + db['IN'], db['UU']))
elif db['IN'] == 0 and db['IU'] > 0 and db['NU'] == 0:
    print(max(db['II'] + db['UU'] + db['IU'], db['NN']))
elif db['IN'] == 0 and db['IU'] == 0 and db['NU'] > 0:
    print(max(db['NN'] + db['UU'] + db['NU'], db['II']))
else:
    print(db['II'] + db['NN'] + db['UU'] + db['IN'] + db['NU'] + db['IU'])
