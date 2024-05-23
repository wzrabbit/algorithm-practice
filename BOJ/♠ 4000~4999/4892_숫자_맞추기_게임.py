id = 1

while True:
    N = int(input())

    if N == 0:
        break

    print(f'{id}. {"odd" if N % 2 == 1 else "even"} {N // 2}')
    id += 1
