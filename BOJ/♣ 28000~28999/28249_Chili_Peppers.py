pepper_prices = {
    'Poblano': 1500,
    'Mirasol': 6000,
    'Serrano': 15500,
    'Cayenne': 40000,
    'Thai': 75000,
    'Habanero': 125000,
}

N = int(input())
total_price = 0

for _ in range(N):
    pepper_name = input()
    total_price += pepper_prices[pepper_name]

print(total_price)
