h, l, a, b = map(int, input().split())
print("YES" if (a <= l and b <= 2 * h) or (b <= l and a <= 2 * h) else "NO")
