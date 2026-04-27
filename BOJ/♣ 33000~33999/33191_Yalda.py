budget = int(input())

watermelon = int(input())
if watermelon <= budget:
    print('Watermelon')
    exit()

pomegranates = int(input())
if pomegranates <= budget:
    print('Pomegranates')
    exit()

nuts = int(input())
if nuts <= budget:
    print('Nuts')
    exit()

print('Nothing')
