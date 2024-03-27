import math

A, B, H = map(int, input().split())

if A > B:
    A, B = B, A

if A == B:
    print(-1)
    exit()

outer = H * (B / (B - A))
inner = outer - H

outer = math.sqrt(outer**2 + B**2)
inner = math.sqrt(inner**2 + A**2)

outer_area = outer**2 * math.pi
inner_area = inner**2 * math.pi

print(outer_area - inner_area)
