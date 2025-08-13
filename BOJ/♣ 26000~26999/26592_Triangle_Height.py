T = int(input())

for _ in range(T):
    A, B = map(float, input().split())
    print(f'The height of the triangle is {A / B * 2:.2f} units')
