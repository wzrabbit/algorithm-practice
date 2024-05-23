N = int(input())
db = {
    'Bessie': 0,
    'Maggie': 0,
    'Elsie': 0,
    'Henrietta': 0,
    'Gertie': 0,
    'Daisy': 0,
    'Annabelle': 0
}

for _ in range(N):
    cow_name, amount = input().split()
    amount = int(amount)
    db[cow_name] += amount

db = list(db.items())
db.sort(key=lambda x: x[1])

if db[0][1] == db[-1][1]:
    print('Tie')
    exit()

for i in range(len(db)):
    if db[i][1] != db[0][1]:
        if i == len(db) - 1 or db[i][1] != db[i + 1][1]:
            print(db[i][0])
        else:
            print('Tie')
        
        break
