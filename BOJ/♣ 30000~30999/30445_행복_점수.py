S = input()
happy = 0
gloomy = 0

for cur in S:
    if cur in 'HAPPY':
        happy += 1
    if cur in 'SAD':
        gloomy += 1

if happy == 0 and gloomy == 0:
    print('50.00')
else:
    total = happy + gloomy
    result = (happy * 20000 + total) // (total * 2)
    print(f"{result // 100}.{result % 100:02d}")
