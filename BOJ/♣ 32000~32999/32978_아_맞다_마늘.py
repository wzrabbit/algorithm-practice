input()
ingredients = input().split()
candidates = set(input().split())

for ingredient in ingredients:
    if ingredient not in candidates:
        print(ingredient)
        exit()
