while True:
    A, B = map(int, input().split())

    if A == 0:
        break

    print(f"{A // B} {A % B} / {B}")
