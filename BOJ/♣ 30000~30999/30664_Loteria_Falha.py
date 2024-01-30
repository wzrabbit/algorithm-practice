while True:
    N = int(input())

    if N == 0:
        break

    if N % 42 == 0:
        print("PREMIADO")
    else:
        print("TENTE NOVAMENTE")
