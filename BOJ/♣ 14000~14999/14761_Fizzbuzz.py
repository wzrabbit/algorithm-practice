F, B, N = map(int, input().split())

for i in range(1, N + 1):
    if i % F == 0 and i % B == 0:
        print('FizzBuzz')
        continue

    if i % F == 0:
        print('Fizz')
        continue

    if i % B == 0:
        print('Buzz')
        continue

    print(i)
