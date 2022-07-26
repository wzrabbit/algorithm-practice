no = input()
alphabet = []
num = []
alphabet_list = []
num_list = []
final_set = set()
perm = (
    (0, 1, 2),
    (0, 2, 1),
    (1, 0, 2),
    (1, 2, 0),
    (2, 0, 1),
    (2, 1, 0)
)

for i in (0, 4, 5):
    alphabet.append(no[i])

for i in (1, 2, 3):
    num.append(no[i])

for x, y, z in perm:
    alphabet_list.append(alphabet[x] + alphabet[y] + alphabet[z])

for x, y, z in perm:
    num_list.append(num[x] + num[y] + num[z])

for i in range(6):
    for j in range(6):
        final_set.add(
            alphabet_list[i][0] +
            num_list[j] +
            alphabet_list[i][1:]
        )

final_set = list(final_set)
print(len(final_set))
for i in range(len(final_set)):
    print(final_set[i])
