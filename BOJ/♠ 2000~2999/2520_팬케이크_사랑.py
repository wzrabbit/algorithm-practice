n = int(input())
for _ in range(n):
    input()
    a, b, c, d, e = map(int, input().split())
    a, b, c, d, e = a * 16, b * 16, c * 16, d * 16, e * 16
    dough = min(a // 8, b // 8, c // 4, d, e // 9)

    f, g, h, i = map(int, input().split())
    pancake = min(dough, f + g // 30 + h // 25 + i // 10)

    print(pancake)
