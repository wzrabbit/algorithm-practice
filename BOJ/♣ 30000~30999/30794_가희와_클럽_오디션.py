N, result = input().split()
N = int(N)

if result == 'miss':
    print(0)
elif result == 'bad':
    print(200 * N)
elif result == 'cool':
    print(400 * N)
elif result == 'great':
    print(600 * N)
else:
    print(1000 * N)
