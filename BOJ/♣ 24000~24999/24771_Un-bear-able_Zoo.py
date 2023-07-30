list_no = 1

while True:
    N = int(input())
    animals = dict()

    if N == 0:
        break

    for _ in range(N):
        animal = input().split()[-1].lower()
        if animal in animals:
            animals[animal] += 1
        else:
            animals[animal] = 1

    animals = sorted(list(animals.items()))

    print(f"List {list_no}:")

    for animal, count in animals:
        print(f"{animal} | {count}")

    list_no += 1
