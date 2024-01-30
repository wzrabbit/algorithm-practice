people = []

for _ in range(3):
    people.append(int(input()))

print(
    min(
        people[1] * 2 + people[2] * 4,
        people[0] * 2 + people[2] * 2,
        people[0] * 4 + people[1] * 2,
    )
)
