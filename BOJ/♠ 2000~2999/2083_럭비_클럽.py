while True:
    name, age, weight = input().split()
    age = int(age)
    weight = int(weight)

    if name == '#':
        break

    if age > 17 or weight >= 80:
        print(f'{name} Senior')
    else:
        print(f'{name} Junior')
