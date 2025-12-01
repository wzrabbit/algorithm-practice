visa_prices = {
    'south-africa': 0,
    'botswana': 0,
    'zimbabwe': 30,
    'kenya': 50,
    'ethiopia': 50,
    'zambia': 50,
    'tanzania': 50,
    'namibia': 140
}

N = int(input())
countries = [input() for _ in range(N)]
cost = 0
south_africa_visited = False

for i in range(N):
    cost += visa_prices[countries[i]]

    if countries[i] == 'south-africa':
        south_africa_visited = True

    if i == 0:
        continue

    if (countries[i - 1], countries[i]) in (('zambia', 'zimbabwe'), ('zimbabwe', 'zambia')):
        cost -= 30
    
    if countries[i] == 'namibia' and south_africa_visited:
        cost -= 100

print(cost)
