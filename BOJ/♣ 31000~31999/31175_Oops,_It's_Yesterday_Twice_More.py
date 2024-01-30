N, R, C = map(int, input().split())

is_top = R - 1 <= N - R
is_left = C - 1 <= N - C
is_top_left = is_top and is_left
is_top_right = is_top and not is_left
is_bottom_left = not is_top and is_left

if is_top_left:
    print("U" * (N - 1) + "L" * (N - 1), end="")
    print("D" * (R - 1) + "R" * (C - 1))
    exit()

if is_top_right:
    print("U" * (N - 1) + "R" * (N - 1), end="")
    print("D" * (R - 1) + "L" * (N - C))
    exit()

if is_bottom_left:
    print("D" * (N - 1) + "L" * (N - 1), end="")
    print("U" * (N - R) + "R" * (C - 1))
    exit()

print("D" * (N - 1) + "R" * (N - 1), end="")
print("U" * (N - R) + "L" * (N - C))
