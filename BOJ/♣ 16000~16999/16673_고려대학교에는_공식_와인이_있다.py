C, K, P = map(int, input().split())
wine = 0

for i in range(1, C + 1):
    wine += K * i + P * (i ** 2)

print(wine)
