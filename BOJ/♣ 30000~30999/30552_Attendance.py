N = int(input())
data = [input() for _ in range(N)]
has_absent = False

for i in range(N - 1):
    if data[i] != 'Present!' and data[i + 1] != 'Present!':
        print(data[i])
        has_absent = True

if data[N - 1] != 'Present!':
    print(data[N - 1])
    has_absent = True

if not has_absent:
    print('No Absences')
