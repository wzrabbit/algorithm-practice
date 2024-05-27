N = int(input())
db = dict()

for _ in range(N):
    name, jewelry = input().split()
    
    if jewelry == '-':
        continue
    
    if jewelry not in db:
        db[jewelry] = []
        
    db[jewelry].append(name)
        
db = list(db.values())
couple_count = 0
answer = []

for i in range(len(db)):
    cur = db[i]
    
    if len(cur) == 2:
        couple_count += 1
        answer.append(f'{cur[0]} {cur[1]}')

print(couple_count)

if couple_count >= 1:
    print('\n'.join(answer))
