def output_triangle(size):
    for i in range(1, size + 1):
        print("*" * i)

while True:
    N = int(input())

    if N == 0:
        break

    output_triangle(N)
